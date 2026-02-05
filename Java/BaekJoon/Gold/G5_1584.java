import java.io.*;
import java.util.*;

class Node implements Comparable<Node> {
    int row, col, life;

    public Node(int row, int col, int life) {
        this.row = row;
        this.col = col;
        this.life = life;
    }

    @Override
    public int compareTo(Node other) {
        return Integer.compare(life, other.life);   // 오름차순 정렬
    }
}

public class Main {
    static ArrayList<ArrayList<Integer>> game_map = new ArrayList<>();
    static ArrayList<ArrayList<Integer>> use_life = new ArrayList<>();

    static int dijkstra(int row, int col) {
        PriorityQueue<Node> pque = new PriorityQueue<>();
        pque.add(new Node(row, col, 0));

        use_life.get(row).set(col, 0);

        while(!pque.isEmpty()) {
            Node now = pque.poll();

            if (use_life.get(now.row).get(now.col) < now.life) continue;

            int[] dy = {-1, 1, 0, 0};
            int[] dx = {0, 0, -1, 1};

            for (int i = 0; i < 4; i++) {
                int ny = now.row + dy[i];
                int nx = now.col + dx[i];

                if (ny < 0 || ny > 500 || nx < 0 || nx > 500) continue;
                if (game_map.get(ny).get(nx) == 2) continue;

                int nLife = game_map.get(ny).get(nx) + now.life;
                if (use_life.get(ny).get(nx) <= nLife) continue;

                pque.add(new Node(ny, nx, nLife));
                use_life.get(ny).set(nx, nLife);
            }
        }

        if (use_life.get(500).get(500) == Integer.MAX_VALUE) return -1;

        return use_life.get(500).get(500);
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 지도 및 기록지 초기화
        for (int i = 0; i < 501; i++) {
            game_map.add(new ArrayList<>());
            use_life.add(new ArrayList<>());

            for (int j = 0; j < 501; j++) {
                game_map.get(i).add(0);
                use_life.get(i).add(Integer.MAX_VALUE);
            }
        }

        // 위험한 구역 지정: 1
        int N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());

            if (x1 > x2) {
                int temp = x2;
                x2 = x1;
                x1 = temp;
            }

            if (y1 > y2) {
                int temp = y2;
                y2 = y1;
                y1 = temp;
            }

            for (int y = y1; y <= y2; y++) {
                for (int x = x1; x <= x2; x++) {
                    game_map.get(y).set(x, 1);
                }
            }
        }

        // 죽음의 구역 지정: 2
        int M = Integer.parseInt(br.readLine());

        for (int i = 0; i < M; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());

            if (x1 > x2) {
                int temp = x2;
                x2 = x1;
                x1 = temp;
            }

            if (y1 > y2) {
                int temp = y2;
                y2 = y1;
                y1 = temp;
            }

            for (int y = y1; y <= y2; y++) {
                for (int x = x1; x <= x2; x++) {
                    game_map.get(y).set(x, 2);
                }
            }
        }

        int result = dijkstra(0, 0);

        System.out.println(result);
    }
}