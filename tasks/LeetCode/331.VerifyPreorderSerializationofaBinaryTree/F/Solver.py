from collections import Counter

class Solution:
    def isValidSerialization(self, preorder: str) -> bool:  
        T, F = True, False
        xs = preorder.split(',')
        for k, v in Counter(xs).items():
            if (k != '#' and v > 1):
                return F
        
        def dfs(idx):
            if (xs[idx] == '#'):
                return 1, 1
            R, L = 1, 1
            if (len(xs) - idx >= 3):
                R0, L0 = dfs(idx + 1)
                R1, L1 = dfs(idx + 1 + L0)
                R = R0 & R1
                L = L0 + L1 + 1
            else:
                R = 0
                L = 0
            return R, L
            
        R, L = dfs(0)
        return T if R and L == len(xs) else F

if __name__ == '__main__':
    print(Solution().isValidSerialization(input()))
