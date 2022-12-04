from itertools import combinations, permutations

# !!! THIS SOLUTION IS FOR 4 POINTS ONLY, BECAUSE OF BAD TIME COMPLEXITY !!!

def solve():
    n, k = [int(i) for i in input().split()]
    l = []
    for _ in range(n):
        l.append([int(i) for i in input().split()])

    combs = combinations(range(n), k)
    mmax = 0
    best_matching, best_matching_vals = [], []
    for c in combs:
        for p in permutations(c):
            print(p)
            matching = [-1 for _ in range(n)]
            for i, o in enumerate(p):
                matching[o] = i 
            for i, m in enumerate(matching):
                if m == -1:
                    matching[i] = l[i].index(max(l[i]))
            
            matching_vals = [l[i][j] for i, j in enumerate(matching)]
                
            if sum(matching_vals) > mmax:
                best_matching = matching
                best_matching_vals = matching_vals
                mmax = sum(matching_vals)
                
    print(sum(best_matching_vals))
    print(*[i + 1 for i in best_matching])
        
t = int(input())
for _ in range(t):
    solve()