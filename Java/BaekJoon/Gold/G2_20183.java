package BaekJoon.Gold;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

class Node implements Comparable<Node> {
    int node;
    long dist;

    public Node(int node, long dist) {
        this.node = node;
        this.dist = dist;
    }

    @Override
    public int compareTo(Node right) {
        if (dist != right.dist) {
            return Long.compare(dist, right.dist);
        }

        return 0;
    }
}

public class G2_20183 {
    public static boolean bfs(int n, long value, List<List<Node>> graph, int a, int b, long c) {
        // 거리 저장 배열 초기화
        List<Long> dist = new ArrayList<>();
        for (int i = 0; i < n + 1; i++) {
            dist.add(Long.MAX_VALUE);
        }

        Queue<Node> pque = new PriorityQueue<>();
        pque.add(new Node(a, 0L));

        dist.set(a, 0L);

        while (!pque.isEmpty()) {
            Node now = pque.poll();

            if (now.dist > dist.get(now.node))
                continue;

            for (int i = 0; i < graph.get(now.node).size(); i++) {
                Node next = graph.get(now.node).get(i);

                if (next.dist > value)
                    continue;

                long next_dist = now.dist + next.dist;

                if (next_dist > c)
                    continue;

                if (next_dist >= dist.get(next.node))
                    continue;

                pque.add(new Node(next.node, next_dist));
                dist.set(next.node, next_dist);
            }
        }

        if (dist.get(b) != Long.MAX_VALUE) {
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
        long c = sc.nextLong();

        // 그래프 초기화
        List<List<Node>> graph = new ArrayList<>();
        ;
        for (int i = 0; i < n + 1; i++) {
            graph.add(new ArrayList<>());
        }

        // 그래프 입력
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            long cost = sc.nextLong();

            graph.get(u).add(new Node(v, cost));
            graph.get(v).add(new Node(u, cost));
        }

        long lo = 1;
        long hi = 1000000000;
        long answer = -1;

        while (lo <= hi) {
            long mid = (lo + hi) / 2;

            boolean res = bfs(n, mid, graph, a, b, c);

            if (res) {
                hi = mid - 1;
                answer = mid;
            } else {
                lo = mid + 1;
            }
        }

        System.out.println(answer);

        sc.close();
    }
}
