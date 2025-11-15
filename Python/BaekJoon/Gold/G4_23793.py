import sys
import heapq

def bfs(start, end, type):
    global graph, y
    dist = [float("inf") for _ in range(n + 1)]
    pque = [(0, start)]

    while pque:
        now_cost, now_node = heapq.heappop(pque)

        if now_cost > dist[now_node]:
            continue

        for node, cost in graph[now_node]:
            next_cost = cost + now_cost

            if (type and node == y):
                continue

            if (dist[node] <= next_cost):
                continue

            heapq.heappush(pque, (next_cost, node))
            dist[node] = next_cost

    return dist[end]


n, m = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(n + 1)]

for _ in range(m):
    u, v, w = map(int, sys.stdin.readline().split())

    graph[u].append((v, w))


x, y, z = map(int, sys.stdin.readline().split())

# x -> y -> z 경로 탐색
temp = bfs(x, y, False)
if temp == float("inf"):
    print(-1, end=" ")
else:
    temp += bfs(y, z, False)

    if temp == float("inf"):
        print(-1, end=" ")
    else:
        print(temp, end=" ")


# x -> z 경로 탐색 (Y 방문 X)
temp = bfs(x, z, True)
if (temp == float("inf")):
    print(-1, end=" ")
else:
    print(temp)