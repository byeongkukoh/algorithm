import heapq

INF = int(10e9)

game_map = [[0 for i in range(501)] for j in range(501)]
use_life = [[INF for i in range(501)] for j in range(501)]

# 위험한 구역 설정
N = int(input())

for _ in range(N):
    x1, y1, x2, y2 = map(int, input().split())
    
    if (x1 > x2):
        x1, x2 = x2, x1

    if (y1 > y2):
        y1, y2 = y2, y1

    for i in range(x1, x2 + 1):
        for j in range(y1, y2 + 1):
            game_map[i][j] = 1


# 죽음의 구역 설정
M = int(input())

for _ in range(M):
    x1, y1, x2, y2 = map(int, input().split())

    if (x1 > x2):
        x1, x2 = x2, x1

    if (y1 > y2):
        y1, y2 = y2, y1

    for i in range(x1, x2 + 1):
        for j in range(y1, y2 + 1):
            game_map[i][j] = 2


dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

# start = 0, 0, 0 (life, row, col)
pque = []
# life, row, col
heapq.heappush(pque, (0, 0, 0))
use_life[0][0] = 0

while len(pque) != 0:
    now = heapq.heappop(pque)

    if (use_life[now[1]][now[2]] < now[0]):
        continue

    for i in range(4):
        ny = now[1] + dy[i]
        nx = now[2] + dx[i]

        if ny < 0 or ny > 500 or nx < 0 or nx > 500:
            continue

        if game_map[ny][nx] == 2:
            continue

        nLife = game_map[ny][nx] + now[0]

        if (use_life[ny][nx] <= nLife):
            continue

        heapq.heappush(pque, (nLife, ny, nx))
        use_life[ny][nx] = nLife

if use_life[500][500] == INF:
    print(-1)
else:
    print(use_life[500][500])
