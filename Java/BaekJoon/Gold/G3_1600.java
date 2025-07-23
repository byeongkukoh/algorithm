package BaekJoon.Gold;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Node {
    int row, col, cnt;

    Node(int row, int col, int cnt) {
        this.row = row;
        this.col = col;
        this.cnt = cnt;
    }
}

public class G3_1600 {
    public static int k, h, w;
    public static int[][] map = new int[200][200];
    public static int[][][] visited = new int[200][200][31];

    public static int[] dy = {-1, 1, 0, 0};
    public static int[] dx = {0, 0, -1, 1};

    public static int[] h_dy = {-2, -2, -1, 1, 2, 2, 1, -1};
    public static int[] h_dx = {-1, 1, 2, 2, 1, -1, -2, -2};

    public static void bfs(int y, int x) {
        Queue<Node> que = new LinkedList<>();
        que.add(new Node(y, x, 0));

        visited[0][0][0] = 0;

        while(!que.isEmpty()) {
            Node now = que.poll();

            for (int i = 0; i < 4; i++) {
                int ny = now.row + dy[i];
                int nx = now.col + dx[i];

                if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
                if (map[ny][nx] == 1) continue;

                if (visited[ny][nx][now.cnt] == -1) {
                    que.add(new Node(ny, nx, now.cnt));
                    visited[ny][nx][now.cnt] = visited[now.row][now.col][now.cnt] + 1;
                }
            }

            if (now.cnt < k) {
                for (int i = 0; i < 8; i++) {
                    int ny = now.row + h_dy[i];
                    int nx = now.col + h_dx[i];

                    if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
                    if (map[ny][nx] == 1) continue;

                    if (visited[ny][nx][now.cnt + 1] == -1) {
                        que.add(new Node(ny, nx, now.cnt + 1));
                        visited[ny][nx][now.cnt + 1] = visited[now.row][now.col][now.cnt] + 1;
                    }
                }
            }
            
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        k = sc.nextInt();
        w = sc.nextInt();
        h = sc.nextInt();

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                map[i][j] = sc.nextInt();
            }
        }

        for (int row = 0; row < 200; row++) {
            for (int col = 0; col < 200; col++) {
                for (int cnt = 0; cnt < 31; cnt++) {
                    visited[row][col][cnt] = -1;
                }
            }
        }

        bfs(0, 0);

        int res = -1;

        for (int cnt = 0; cnt <= k; cnt++) {
            int now = visited[h - 1][w - 1][cnt];

            if (now == -1) continue;
            if (res == -1 || res > now) res = now;
        }

        System.out.println(res);

        sc.close();
    }
}