package BaekJoon.Gold;

import java.io.*;
import java.util.*;
import java.math.*;

public class G5_5972 {

    static class Edge {
        int node, cost;

        Edge(int node, int cost) {
            this.node = node;
            this.cost = cost;
        }
    }

    static class Node implements Comparable<Node> {
        int node, cost;

        Node(int node, int cost) {
            this.node = node;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node other) {
            return Integer.compare(this.cost, other.cost);
        }

    }

    static ArrayList<Edge>[] graph;
    static int[] cost;

    private static void dijkstra(int start) {
        Queue<Node> pque = new PriorityQueue<>();
        pque.add(new Node(start, 0));
        cost[start] = 0;

        while (!pque.isEmpty()) {
            Node now = pque.poll();

            if (now.cost > cost[now.node])
                continue;

            for (Edge next : graph[now.node]) {
                if (cost[next.node] <= cost[now.node] + next.cost)
                    continue;

                cost[next.node] = cost[now.node] + next.cost;
                pque.add(new Node(next.node, cost[next.node]));
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        // 배열 초기화
        graph = new ArrayList[n + 1];
        cost = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            graph[i] = new ArrayList<Edge>();
            cost[i] = Integer.MAX_VALUE;
        }

        // 초기 값 입력
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());

            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            graph[from].add(new Edge(to, cost));
            graph[to].add(new Edge(from, cost));
        }

        dijkstra(1);

        System.out.println(cost[n]);
    }
}