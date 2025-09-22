package BaekJoon.Gold;

import java.util.*;

class Node implements Comparable<Node> {
    public int node;
    public int dist;

    public Node(int node, int dist) {
        this.node = node;
        this.dist = dist;
    }

    @Override
    public int compareTo(Node right) {
        return Integer.compare(this.dist, right.dist);
    }
}

public class G2_9370 {
    public static void dijkstra(int start, List<List<Node>> map, List<Integer> dist) {
        Queue<Node> pque = new PriorityQueue<>();
        pque.add(new Node(start, 0));

        dist.set(start, 0);

        while(!pque.isEmpty()) {
            Node now = pque.poll();

            if (dist.get(now.node) < now.dist) continue;

            for (int i = 0; i < map.get(now.node).size(); i++) {
                Node next = map.get(now.node).get(i);
                int nextDist = now.dist + next.dist;

                if (dist.get(next.node) <= nextDist) continue;

                pque.add(new Node(next.node, nextDist));
                dist.set(next.node, nextDist);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int TC = sc.nextInt();

        for (int test = 0; test < TC; test++) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int t = sc.nextInt();

            int s = sc.nextInt();
            int g = sc.nextInt();
            int h = sc.nextInt();

            List<List<Node>> map = new ArrayList<>();
            for (int i = 0; i < n + 1; i++) {
                map.add(new ArrayList<>());
            }

            int weight = 0;
            for (int i = 0; i < m; i++) {
                int from = sc.nextInt();
                int to = sc.nextInt();
                int cost = sc.nextInt();

                if ((from == g && to == h) || (from == h && to == g)) {
                    weight = cost;
                }

                map.get(from).add(new Node(to, cost));
                map.get(to).add(new Node(from, cost));
            }

            List<Integer> targets = new ArrayList<>();
            for (int i = 0; i < t; i++) {
                int temp = sc.nextInt();

                targets.add(temp);
            }
            Collections.sort(targets);

            // Dijkstra from start
            List<Integer> distS = new ArrayList<>();
            for (int i = 0; i < n + 1; i++) {
                distS.add(Integer.MAX_VALUE);
            }
            dijkstra(s, map, distS);
            
            // Dijkstra from g
            List<Integer> distG = new ArrayList<>();
            for (int i = 0; i < n + 1; i++) {
                distG.add(Integer.MAX_VALUE);
            }
            dijkstra(g, map, distG);

            // Dijkstra from h
            List<Integer> distH = new ArrayList<>();
            for (int i = 0; i < n + 1; i++) {
                distH.add(Integer.MAX_VALUE);
            }
            dijkstra(h, map, distH);

            // check path
            for (int i = 0; i < targets.size(); i++) {
                int target = distS.get(targets.get(i));

                int path1 = distS.get(h) + weight + distG.get(targets.get(i));
                int path2 = distS.get(g) + weight + distH.get(targets.get(i));

                if ((target == path1) || (target == path2)) {
                    System.out.print(targets.get(i));
                    System.out.print(" ");
                }
            }

            System.out.println();
        }
        
        sc.close();
    }
}
