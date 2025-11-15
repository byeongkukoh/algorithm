package BaekJoon.Gold;

import java.util.*;

class Coord {
    int row;
    int col;

    public Coord(int row, int col) {
        this.row = row;
        this.col = col;
    }
}

public class G4_17141 {
    public static int n, m;
    public static int timer = Integer.MAX_VALUE;

    public static List<Coord> start_point = new ArrayList<>();
    public static List<Coord> use_point = new ArrayList<>();
    public static List<List<Integer>> map = new ArrayList<>();

    public static int bfs() {
        // 방문 체크 배열 초기화
        List<List<Integer>> timecheck = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            timecheck.add(new ArrayList<>());

            for (int j = 0; j < n; j++) {
                timecheck.get(i).add(-1);
            }
        }

        Queue<Coord> que = new LinkedList<>();

        // 큐에 시작점 추가
        for (int i = 0; i < m; i++) {
            que.add(use_point.get(i));
            timecheck.get(use_point.get(i).row).set(use_point.get(i).col, 0);
        }

        int[] dy = { -1, 1, 0, 0 };
        int[] dx = { 0, 0, -1, 1 };
        while (!que.isEmpty()) {
            Coord now = que.poll();

            for (int i = 0; i < 4; i++) {
                int ny = now.row + dy[i];
                int nx = now.col + dx[i];

                if (ny < 0 || nx < 0 || ny >= n || nx >= n) {
                    continue;
                }

                if (map.get(ny).get(nx) == 1) {
                    continue;
                }

                if (timecheck.get(ny).get(nx) != -1) {
                    continue;
                }

                que.add(new Coord(ny, nx));
                timecheck.get(ny).set(nx, timecheck.get(now.row).get(now.col) + 1);
            }
        }

        // 완전히 확산되는데 걸리는 시간
        int res = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map.get(i).get(j) == 1) {
                    continue; // 벽 무시
                }

                if (timecheck.get(i).get(j) == -1) {
                    return -1; // 퍼지지 않은 곳이 있으면 -1 반환
                }

                // 시간 체크 (최대 시간)
                if (res < timecheck.get(i).get(j)) {
                    res = timecheck.get(i).get(j);
                }

            }
        }

        return res;
    }

    public static void backtracking(int now, int idx) {
        if (now == m) {
            int temp = bfs();

            if (temp == -1) {
                return;
            }

            if (temp < timer) {
                timer = temp;
            }

            return;
        }

        for (int i = idx; i < start_point.size(); i++) {
            use_point.add(start_point.get(i));

            backtracking(now + 1, i + 1);

            use_point.remove(use_point.size() - 1);
        }

        return;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        // 맵 입력
        for (int i = 0; i < n; i++) {
            map.add(new ArrayList<>());

            for (int j = 0; j < n; j++) {
                int temp = sc.nextInt();
                map.get(i).add(temp);

                if (temp == 2) {
                    start_point.add(new Coord(i, j));
                }
            }
        }

        backtracking(0, 0);

        if (timer == Integer.MAX_VALUE) {
            System.out.println(-1);

            sc.close();

            return;
        }

        System.out.println(timer);

        sc.close();

        return;
    }
}
