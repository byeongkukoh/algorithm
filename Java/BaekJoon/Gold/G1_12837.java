package BaekJoon.Gold;

import java.util.Scanner;

public class G1_12837 {
    public static int N, Q;
    public static long[] tree;

    public static void update(int node, int start, int end, int idx, long val) {
        if(start == end) {
            tree[node] += val;
        } else {
            int mid = (start + end) / 2;

            if (idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }

            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }

    }

    public static long query(int node, int start, int end, int left, int right) {
        if (left > end || right < start) return 0;
        if (left <= start && right >= end) return tree[node];

        int mid = (start + end) / 2;

        long left_sum = query(2 * node, start, mid, left, right);
        long right_sum = query(2 * node + 1, mid + 1, end, left, right);

        return left_sum + right_sum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        Q = sc.nextInt();

        tree = new long[4 * N + 1];

        for (int i = 0; i < Q; i++) {
            int comm = sc.nextInt();

            if (comm == 1) {
                int idx = sc.nextInt();
                long val = sc.nextLong();

                update(1, 1, N, idx, val);
            } else {
                int left = sc.nextInt();
                int right = sc.nextInt();

                long result = query(1, 1, N, left, right);

                System.out.println(result);
            }
        }
        
        sc.close();
    }
}