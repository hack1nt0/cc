#include "debug.h"
#include <limits>

using namespace std;

class Solution {
public:
    int divide(int a, int b) {你好
        using Long = long long;
        int neg_a = a < 0;
        int neg_b = b < 0;
        Long aa = abs(Long(a));
        Long bb = abs(Long(b));
        Long ret = 0;
        while (aa >= bb) {
            if (aa == bb) {
                ret++;
                break;
            }
            Long acc_b = bb;
            Long pow_2 = 1;
            while (true) {
                Long acc_b2 = acc_b + acc_b;
                if (acc_b2 > aa) break;
                acc_b = acc_b2;
                pow_2 <<= 1;
                debug(acc_b, pow_2);
            }
            aa -= acc_b;
            ret += pow_2;
        }
        if (neg_a + neg_b == 1)
            ret = -ret;
        if (ret < numeric_limits<int>::min() || ret > numeric_limits<int>::max())
            ret = numeric_limits<int>::max();
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    cout << Solution().divide(a, b) << endl;
    return 0;
}
