from collections import deque

n, m, k = map(int, input().split())

location = [[0 for _ in range(m + 1)] for _ in range(n + 1)]
visited = [[False for _ in range(m + 1)] for _ in range(n + 1)]

for i in range(k):
    row, col = map(int, input().split())

    location[row][col] = 1

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

result = 0

for i in range(1, n + 1):
    for j in range(1, m + 1):

        if ((location[i][j] == 1) and (visited[i][j] == False)):
            que = deque()
            que.append((i, j))

            visited[i][j] = True

            cnt = 1

            while(len(que) != 0):
                now = que.popleft()

                for dir in range(4):
                    ny = now[0] + dy[dir]
                    nx = now[1] + dx[dir]

                    if (ny < 1 or nx < 1 or ny > n or nx > m): continue
                    if (location[ny][nx] != 1): continue
                    if (visited[ny][nx]): continue

                    que.append((ny, nx))
                    visited[ny][nx] = True
                    
                    cnt += 1
        
            if (result < cnt): result = cnt

print(result)