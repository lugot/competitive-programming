M = int(input())
N = int(input())

d = {}
revd = {}
pizze = {}
base = {}
visited = {}
topo = []

for _ in range(N):
    p1, p2, ingredient, price, prestige = input().split()
    price = int(price)
    prestige = int(prestige)

    if p2 not in base:
        base[p2] = 1
    base[p2] = min(1, base[p2])
    if p1 not in base:
        base[p1] = 0

    visited[p1] = 0
    visited[p2] = 0

    if p2 not in d:
        d[p2] = []
    d[p2].append(p1)
    if p1 not in d:
        d[p1] = []

    if p1 not in revd:
        revd[p1] = []
    revd[p1].append([p2, (price, prestige)])

base = [k for k, v in base.items() if v == 1]


def toposort(node):
    visited[node] = 1
    for u in d[node]:
        if not visited[u]:
            toposort(u)
    topo.append(node)


for node in base:
    toposort(node)
topo = topo[::-1]
# print(topo)
i = 0
while(topo[i] in base):
    pizze[topo[i]] = [0, 0]
    i += 1
# print(topo[i:])

for u in topo[i:]:
    # la prossima volta faccio una struct, non si capisce nulla
    nome_pizza = revd[u][0][0]
    price = revd[u][0][1][0]
    prestige = revd[u][0][1][1]

    pizze[u] = [price + pizze[nome_pizza][0],
                prestige + pizze[nome_pizza][1]]

    for v in revd[u][1:]:
        # print(v)
        nome_pizza = v[0]
        price = v[1][0]
        prestige = v[1][1]

        if price + pizze[nome_pizza][0] < pizze[u][0]:
            pizze[u][0] = price + pizze[nome_pizza][0]
        elif price + pizze[nome_pizza][0] == pizze[u][0]:
            if prestige + pizze[nome_pizza][1] > pizze[u][1]:
                pizze[u][1] = prestige + pizze[nome_pizza][1]

# print(pizze)


def knapSack(W, wt, val, n):
    K = [[0 for x in range(W + 1)] for x in range(n + 1)]
    WW = [[0 for x in range(W + 1)] for x in range(n + 1)]

    for i in range(n + 1):
        for w in range(W + 1):
            if i == 0 or w == 0:
                K[i][w] = 0
                WW[i][w] = 0
            elif wt[i-1] <= w:
                if val[i-1] + K[i-1][w-wt[i-1]] > K[i-1][w]:
                    WW[i][w] = wt[i-1] + WW[i-1][w-wt[i-1]]
                else:
                    WW[i][w] = WW[i-1][w]

                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w])
            else:
                K[i][w] = K[i-1][w]
                WW[i][w] = WW[i-1][w]

    # for x in WW: print(x)
    # print()
    # for x in K: print(x)
    return K[n][W], WW[n][W]


val = [v[1] for k, v in pizze.items()]
wt = [v[0] for k, v in pizze.items()]
n = len(val)
ans = knapSack(M, wt, val, n)
print(ans[0])
print(ans[1])





# def dfs(node):
    # for i in d[node]:
        # pizze[i] = [pizze[i][0] + pizze[node][0], pizze[i][1] + pizze[node][1]]
        # if i in d:
            # dfs(i)

# dfs('pizza_base')

# print(pizze)
