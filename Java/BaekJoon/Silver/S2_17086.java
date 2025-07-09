package BaekJoon.Silver;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Point {
    public int y;
    public int x;

    public Point(int y, int x) {
        this.y = y;
        this.x = x;
    }
}

public class S2_17086 {
    public static int n, m;
    public static int[][] space;

    public static int[] dx = {-1, 0, 1, 1, 1, 0, -1, -1};
    public static int[] dy = {-1, -1, -1, 0, 1, 1, 1, 0};

    public static int bfs(int y, int x) {
        Queue<Point> que = new LinkedList<>();
        que.offer(new Point(y, x));

        int[][] dist = new int[n][m];

        dist[y][x] = 1;

        while(!que.isEmpty()) {
            Point now = que.poll();

            for (int i = 0; i < 8; i++) {
                int ny = now.y + dy[i];
                int nx = now.x + dx[i];
                int nextDist = dist[now.y][now.x] + 1;

                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (dist[ny][nx] != 0) continue;

                if (space[ny][nx] == 1) {
                    return dist[now.y][now.x];
                }

                que.offer(new Point(ny, nx));
                dist[ny][nx] = nextDist;
            }
        }

        return 0;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        space = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                space[i][j] = sc.nextInt();
            }
        }

        int safe = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (space[i][j] == 1) continue;

                int temp = bfs(i, j);

                if (safe < temp) {
                    safe = temp;
                }
            }
        }

        System.out.println(safe);

        sc.close();
    }
}
