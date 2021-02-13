from collections import defaultdict
from heapq import *


def dijkstra(s, t, graph):
    q = [(0, s)] # il vicino, new_time, peso

    dist = {}
    dist[s] = 0

    while q:
        distU, u = heappop(q)

        # if u == t:
            # return distU

        for v, w, t0, p in graph.get(u, ()):
            distV = dist.get(v, None)

            # 15, 25, 35
            # curr_time = 20
            # int(20/15)*15 + 10 = 25

            if p == 0:
                if distU > t0:
                    continue
                else:
                    new_time = t0
            elif t0 == 0: 
                new_time = int(distU/p)*p + p
            else:
                if distU <= t0:
                    new_time = t0
                else:
                    new_time = (int(distU/t0)*t0 + p) 

            # cost = w + distU + (new_time-distU)
            
            # print(u, v, distU, t0, new_time)

            # distV is None mean that d[v] is INF
            if distV is None or distV >= w + new_time:
                dist[v] = w + new_time 
                heappush(q, (distU + w + new_time - distU, v))

    # return "Impossible"
    return dist

while True:
    n, m, q ,s = list(map(int, input().split()))

    if n == 0: break

    graph = defaultdict(list)
    for _ in range(m):
        u, v, t0, p, d = list(map(int, input().split()))
        graph[u].append((v, d, t0, p)) # destinazione, new_time, start, intervallo

    dist = dijkstra(s, 1, graph)

    for _ in range(q):
        t = int(input())
        if t not in dist.keys(): print("Impossible")
        else: print(dist[t])

    print()
