package BaekJoon.Gold;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

class Node implements Comparable<Node> {
    int node;
    int dist;

    public Node(int node, int dist) {
        this.node = node;
        this.dist = dist;
    }

    @Override
    public int compareTo(Node right) {
        if (this.dist != right.dist)
            return Integer.compare(this.dist, right.dist);

        return 0;
    }
}

public class G3_20182 {
    public static boolean bfs(int n, List<List<Node>> graph, int mid, int a, int b, int c) {
        // 거리 배열 초기화
        List<Integer> dist = new ArrayList<>();
        for (int i = 0; i < n + 1; i++) {
            dist.add(Integer.MAX_VALUE);
        }

        Queue<Node> pque = new PriorityQueue<>();
        pque.add(new Node(a, 0));

        dist.set(a, 0);

        while (!pque.isEmpty()) {
            Node now = pque.poll();

            if (now.dist > dist.get(now.node)) {
                continue;
            }

            for (int i = 0; i < graph.get(now.node).size(); i++) {
                int next_node = graph.get(now.node).get(i).node;
                int next_cost = graph.get(now.node).get(i).dist;

                if (next_cost > mid) {
                    continue;
                }

                int next_dist = next_cost + now.dist;

                if (next_dist >= dist.get(next_node)) {
                    continue;
                }

                if (next_dist > c) {
                    continue;
                }

                dist.set(next_node, next_dist);
                pque.add(new Node(next_node, next_dist));
            }
        }

        if (dist.get(b) != Integer.MAX_VALUE) {
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        // 그래프 초기화
        List<List<Node>> graph = new ArrayList<>();
        for (int i = 0; i < n + 1; i++) {
            graph.add(new ArrayList<>());
        }

        // 그래프 초기값 입력
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int cost = sc.nextInt();

            graph.get(u).add(new Node(v, cost));
            graph.get(v).add(new Node(u, cost));
        }

        int lo = 1;
        int hi = 20;
        int result = -1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            boolean res = bfs(n, graph, mid, a, b, c);

            if (res) {
                result = mid;

                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        System.out.println(result);

        sc.close();
    }
}
