package BaekJoon.Silver;

import java.util.Scanner;

public class S2_6603 {
    public static void backtracking(int k, int[] nums, int[] path, int now, int idx) {
        if (now == 6) {
            for (int i = 0; i < 6; i++) {
                System.out.print(path[i] + " ");
            }

            System.out.println();

            return;
        }

        for (int i = idx; i < nums.length; i++) {
            path[now] = nums[i];

            backtracking(k, nums, path, now + 1, i + 1);

            path[now] = -1;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            int n = sc.nextInt();

            if (n == 0)
                break;

            int[] nums = new int[n];
            for (int i = 0; i < n; i++) {
                nums[i] = sc.nextInt();
            }

            int[] path = new int[6];

            backtracking(n, nums, path, 0, 0);

            System.out.println();
        }

        sc.close();

        return;
    }
}
