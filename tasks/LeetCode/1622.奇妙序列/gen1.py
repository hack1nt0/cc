O = ["Fancy","append","addAll","append","multAll","getIndex","addAll","append","multAll","getIndex","getIndex","getIndex"]
V = [[],[2],[3],[7],[2],[0],[3],[10],[2],[0],[1],[2]]

n = len(O)
print(n)
for i in range(n):
    print(O[i], V[i][0] if V[i] else 0)
