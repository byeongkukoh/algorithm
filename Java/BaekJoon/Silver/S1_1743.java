package BaekJoon.Silver;

import java.util.Queue;
import java.util.LinkedList;
import java.util.Scanner;

class Node {
    int y;
    int x;

    public Node(int y, int x) {
        this.y = y;
        this.x = x;
    }
}

public class S1_1743 {
    public static int n, m, k;
    public static int[][] map;
    public static boolean[][] visited;

    public static int bfs() {
        int dy[] = {-1, 1, 0, 0};
        int dx[] = {0, 0, -1, 1};
        
        int result = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (map[i][j] == 1 && !visited[i][j]) {
                    int cnt = 1;

                    Queue<Node> que = new LinkedList<>();
                    que.add(new Node(i, j));

                    visited[i][j] = true;

                    while(!que.isEmpty()) {
                        Node now = que.poll();

                        for (int dir = 0; dir < 4; dir++) {
                            int ny = now.y + dy[dir];
                            int nx = now.x + dx[dir];

                            if (ny < 1 || nx < 1 || ny > n || nx > m) continue;
                            if (map[ny][nx] != 1) continue;
                            if (visited[ny][nx]) continue;

                            que.add(new Node(ny, nx));
                            visited[ny][nx] = true;

                            cnt++;
                        }
                    }

                    if (result < cnt) result = cnt;
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();
        k = sc.nextInt();

        map = new int[n + 1][m + 1];
        visited = new boolean[n + 1][m + 1];

        for (int i = 0; i < k; i++) {
            int row, col;
            row = sc.nextInt();
            col = sc.nextInt();

            map[row][col] = 1;
        }

        int result = bfs();

        System.out.println(result);

        sc.close();
    }
}
