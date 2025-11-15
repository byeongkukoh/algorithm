package BaekJoon.Gold;

import java.io.*;
import java.util.*;

class Node implements Comparable<Node> {
    public int node;
    public int cost;

    public Node(int node, int cost) {
        this.node = node;
        this.cost = cost;
    }

    @Override
    public int compareTo(Node right) {
        if (this.cost != right.cost) return Integer.compare(this.cost, right.cost);

        return 0;
    }
}

public class G4_23793 {
    public static int n, m;
    public static int x, y, z;

    public static List<Integer> dist;
    public static List<List<Node>> graph;

    public static void bfs(int start, boolean type) {
        // 거리 배열 초기화
        for (int i = 0; i <= n; i++) {
            dist.set(i, Integer.MAX_VALUE);
        }
        
        Queue<Node> pque = new PriorityQueue<>();
        pque.add(new Node(start, 0));

        dist.set(start, 0);

        while(!pque.isEmpty()) {
            Node now = pque.poll();

            if (now.cost > dist.get(now.node)) continue;

            for (int i = 0; i < graph.get(now.node).size(); i++) {
                int next = graph.get(now.node).get(i).node;
                int nextCost = graph.get(now.node).get(i).cost + now.cost;

                if ((type) && (next == y)) continue;
                if (dist.get(next) <= nextCost) continue;

                pque.add(new Node(next, nextCost));
                dist.set(next, nextCost);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        // 초기 값 입력
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        // 그래프 및 거리 배열 초기화
        graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }

        dist = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            dist.add(Integer.MAX_VALUE);
        }

        // 그래프 입력
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());

            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            graph.get(u).add(new Node(v, w));
        }

        // x, y, z 값 입력
        st = new StringTokenizer(br.readLine());

        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());
        z = Integer.parseInt(st.nextToken());

        // x -> y -> z 경로 탐색
        bfs(x, false);

        if (dist.get(y) == Integer.MAX_VALUE) {
            System.out.print(-1);
            System.out.print(" ");
        } else {
            int temp = dist.get(y);

            bfs(y, false);

            if (dist.get(z) == Integer.MAX_VALUE) {
                System.out.print(-1);
                System.out.print(" ");
            } else {
                System.out.print(temp + dist.get(z));
                System.out.print(" ");
            }
        }

        // x -> z 경로 탐색 (y 방문 X)
        bfs(x, true);

        if (dist.get(z) == Integer.MAX_VALUE) {
            System.out.print(-1);
        } else {
            System.out.print(dist.get(z));
        }
    }
}
