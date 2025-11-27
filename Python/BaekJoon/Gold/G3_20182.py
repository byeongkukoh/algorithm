import sys
import heapq

def bfs(n, graph, mid, a, b, c):
    dist = [float('inf') for _ in range(n + 1)]

    que = [] # (dist, node)
    heapq.heappush(que, (0, a))

    dist[a] = 0

    while(que):
        now_dist, now_node = heapq.heappop(que)

        if (now_dist > dist[now_node]):
            continue

        for next_node, next_cost in graph[now_node]:
            if (next_cost > mid):
                continue

            next_dist = now_dist + next_cost

            if (next_dist >= dist[next_node]):
                continue
            if (next_dist > c):
                continue

            heapq.heappush(que, (next_dist, next_node))
            dist[next_node] = next_dist

    if (dist[b] == float('inf')):
        return False
    else:
        return True


n, m, a, b, c = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(n + 1)]

max_cost = 0

for _ in range(m):
    u, v, cost = map(int, sys.stdin.readline().split())

    if cost > max_cost:
        max_cost = cost

    graph[u].append((v, cost))
    graph[v].append((u, cost))

lo = 1
hi = 20

result = -1

while (lo <= hi):
    mid = (lo + hi) // 2
    res = bfs(n, graph, mid, a, b, c)

    if res:
        result = mid
        hi = mid - 1
    else:
        lo = mid + 1


print(result)