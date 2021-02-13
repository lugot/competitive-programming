from sys import stdin, stdout
import heapq

def man_dist(v1,v2):
    return abs(v1[0]-v2[0]) + abs(v1[1]-v2[1])

def key_weight(e):
    return e[2]

def find_set(v):
    while parent[v]!=v:
        v = parent[v]
    return v

def union(v1,v2):
    if v1==v2:
        return
    if depth[v1] < depth[v2]:
        parent[v1] = v2
    else:
        parent[v2] = v1
        if depth[v1]==depth[v2]:
            depth[v1]


n = int(input())

mst = []
edges = []
vertices = []

parent = [x for x in range(n)]
depth = [1 for x in range(n)]

for i in range(n):
    vertices.append(tuple(map(int,input().split())))

for i in range(n):
    for j in range(i+1,n):
        dist = man_dist(vertices[i],vertices[j])
        edges.append((dist,i,j))

edges.sort()
        
for e in edges:
    set1 = find_set(e[1])
    set2 = find_set(e[2])
    #print(set1,set2)
    if set1!=set2:
        mst.append(e)
        union(set1,set2)

total_weight = 0
for e in mst:
    total_weight += e[0]
    
print(total_weight)
