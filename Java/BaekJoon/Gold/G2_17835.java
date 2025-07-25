package BaekJoon.Gold;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Node implements Comparable<Node> {
    public int node;
    public long cost;

    public Node(int node, long cost) {
        this.node = node;
        this.cost = cost;
    }

    @Override
    public int compareTo(Node right) {
        return Long.compare(this.cost, right.cost);
    }
}

public class G2_17835 {
    public static int n, m, k;

    public static List<List<Node>> map;
    public static List<Long> dist;

    public static void bfs(int start) {
        Queue<Node> pque = new PriorityQueue<>();
        pque.add(new Node(start, 0));

        dist.set(start, 0L);

        while (!pque.isEmpty()) {
            Node now = pque.poll();

            if (dist.get(now.node) < now.cost)
                continue;

            for (int i = 0; i < map.get(now.node).size(); i++) {
                Node next = map.get(now.node).get(i);
                long ndist = now.cost + next.cost;

                if (dist.get(next.node) <= ndist)
                    continue;

                pque.add(new Node(next.node, ndist));
                dist.set(next.node, ndist);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        map = new ArrayList<>();
        for (int i = 0; i < n + 1; i++) {
            map.add(new ArrayList<>());
        }

        dist = new ArrayList<>(n + 1);
        for (int i = 0; i < n + 1; i++) {
            dist.add(Long.MAX_VALUE);
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            map.get(to).add(new Node(from, cost));
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < k; i++) {
            int start = Integer.parseInt(st.nextToken());

            bfs(start);
        }

        int city = 0;
        long res = 0;

        for (int i = 1; i < n + 1; i++) {
            if (dist.get(i) > res) {
                city = i;
                res = dist.get(i);
            }
        }

        System.out.println(city);
        System.out.println(res);
    }
}
