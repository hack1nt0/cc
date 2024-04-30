from bisect import bisect_left, bisect_right

class Solution:
    def findMedianSortedArrays(self, nums1, nums2) -> float:
        n = len(nums1)
        m = len(nums2)
        if n + m == 0:
            return 0
        def med(xs):
            return xs[len(xs) // 2] if len(xs) % 2 else (xs[len(xs) // 2 - 1] + xs[len(xs) // 2]) / 2
        if n == 0:
            return med(nums2)
        if m == 0:
            return med(nums1)
        
        L = n + m
        def find(A, B, M):
            l, r = 0, len(A) - 1
            while l <= r:
                mid = (l + r) // 2
                lb1 = bisect_left(A, A[mid])
                rb1 = bisect_right(A, A[mid])
                lb2 = bisect_left(B, A[mid])
                rb2 = bisect_right(B, A[mid])
                if lb1 + lb2 < M <= rb1 + rb2:
                    return A[mid]
                if M <= lb1 + lb2:
                    r = mid - 1
                else:
                    l = mid + 1
            return None
        
        ia = (L + 1) // 2
        ib = ia if L % 2 else ia + 1
        a = find(nums1, nums2, ia)
        if a is None:
            a = find(nums2, nums1, ia)
        b = find(nums1, nums2, ib)
        if b is None:
            b = find(nums2, nums1, ib)
        return (a + b) / 2

if __name__ == '__main__':
	A = list(map(int, input()[1:-1].split(',')))
	B = list(map(int, input()[1:-1].split(',')))
	print(Solution().findMedianSortedArrays(A, B))