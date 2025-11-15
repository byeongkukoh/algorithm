package BaekJoon.Silver;

import java.util.*;

public class S1_14888 {
    public static int n;

    public static List<Integer> nums = new ArrayList<>();
    public static int[] oper = new int[4];
    public static List<Integer> path = new ArrayList<>();;

    public static int max_ans = Integer.MIN_VALUE;
    public static int min_ans = Integer.MAX_VALUE;

    public static void backtracking(int now) {
        if (now == n - 1) {
            int temp = nums.get(0);

            for (int i = 0; i < path.size(); i++) {
                if (path.get(i) == 0) {
                    temp += nums.get(i + 1);
                } else if (path.get(i) == 1) {
                    temp -= nums.get(i + 1);
                } else if (path.get(i) == 2) {
                    temp *= nums.get(i + 1);
                } else {
                    temp /= nums.get(i + 1);
                }
            }

            if (max_ans < temp) max_ans = temp;
            if (min_ans > temp) min_ans = temp;

            return;
        }

        for (int i = 0; i < 4; i++) {
            if (oper[i] == 0) continue;

            oper[i] -= 1;
            path.add(i);

            backtracking(now + 1);

            oper[i] += 1;
            path.remove(path.size() - 1);
        }

        return;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            nums.add(sc.nextInt());
        }

        for (int i = 0; i < 4; i++) {
            oper[i] = sc.nextInt();
        }

        backtracking(0);

        System.out.println(max_ans);
        System.out.println(min_ans);

        sc.close();
    }
}
