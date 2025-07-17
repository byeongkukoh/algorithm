package BaekJoon.Platinum;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P5_1306 {
    public static int N, M;
    public static int[] light;
    public static int[] tree;

    public static void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = light[start];
        } else {
            int mid = (start + end) / 2;

            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);

            tree[node] = Math.max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    public static int query(int node, int start, int end, int left, int right) {
        if (left > end || right < start) return 0;
        if (left <= start && right >= end) return tree[node];

        int mid = (start + end) / 2;
        int left_max = query(2 * node, start, mid, left, right);
        int right_max = query(2 * node + 1, mid + 1, end, left, right);

        return Math.max(left_max, right_max);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        light = new int[N + 1];
        tree = new int[4 * N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i < N + 1; i++) {
            light[i] = Integer.parseInt(st.nextToken());
        }

        build(1, 1, N);

        StringBuilder sb = new StringBuilder();
        for (int i = M; i <= N - M + 1; i++) {
            sb.append(query(1, 1, N, i - M + 1, i + M - 1));
            sb.append(" ");
        }
        System.out.println(sb);
    }
}
