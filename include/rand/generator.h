#ifndef INCLUDED_SEQUENCES_H
#define INCLUDED_SEQUENCES_H

#include "debug.h"
#include <coroutine>

/*
    https://en.cppreference.com/w/cpp/language/coroutines
*/
template <typename T> struct Generator {
    // The class name 'Generator' is our choice and it is not required for
    // coroutine magic. Compiler recognizes coroutine by the presence of
    // 'co_yield' keyword. You can use name 'MyGenerator' (or any other name)
    // instead as long as you include nested struct promise_type with
    // 'MyGenerator get_return_object()' method.

    using generator_type = Generator<T>;

    struct promise_type {
        T value_;
        std::exception_ptr exception_;

        Generator get_return_object() {
            return Generator(handle_type::from_promise(*this));
        }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        void unhandled_exception() {
            exception_ = std::current_exception();
        } // saving
          // exception

        template <std::convertible_to<T> From> // C++20 concept
        std::suspend_always yield_value(From &&from) {
            value_ = std::forward<From>(from); // caching the result in promise
            return {};
        }
        void return_void() {}
    };

    using handle_type = std::coroutine_handle<promise_type>;

    handle_type handle;

    Generator(handle_type h) : handle(h) {}
    ~Generator() { handle.destroy(); }
    explicit operator bool() {
        fill(); // The only way to reliably find out whether or not we finished
                // coroutine, whether or not there is going to be a next value
                // generated (co_yield) in coroutine via C++ getter (operator ()
                // below) is to execute/resume coroutine until the next co_yield
                // point (or let it fall off end). Then we store/cache result in
                // promise to allow getter (operator() below to grab it without
                // executing coroutine).
        return !handle.done();
    }
    // next()
    T operator()() {
        fill();
        full = false; // we are going to move out previously cached
                      // result to make promise empty again
        return std::move(handle.promise().value_);
    }

    // T get_val() {
    //     fill();
    //     return std::move(handle.promise().value_);
    // }

    struct iterator {
        using iterator_category = std::input_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T *;
        using reference = T&;

        explicit iterator(generator_type &g) : g(g) {}
        T operator*() { return g(); }
        iterator &operator++() {
            g.full = false;
            return *this;
        }
        bool operator!=(iterator other) const { return bool((*this).g); }

      private:
        generator_type &g;
    };
    iterator begin() { return iterator(*this); }
    iterator end() { return iterator(*this); }

  private:
    bool full = false;

    void fill() {
        if (!full) {
            handle();
            if (handle.promise().exception_)
                std::rethrow_exception(handle.promise().exception_);
            // propagate coroutine exception in called context

            full = true;
        }
    }
};


#endif