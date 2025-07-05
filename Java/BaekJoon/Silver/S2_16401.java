package BaekJoon.Silver;

import java.util.Arrays;
import java.util.Scanner;

public class S2_16401 {
    public static int m, n;
    public static int[] snack = new int[1000000];

    public static boolean check(int leng) {
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (snack[i] >= leng) {
                cnt += snack[i] / leng;
            }
        }

        return cnt >= m;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        m = sc.nextInt();
        n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            int temp = sc.nextInt();
            snack[i] = temp;
        }

        Arrays.sort(snack, 0, n);

        int lo = 1;
        int hi = snack[n - 1];

        int leng = 0;

        while(lo <= hi) {
            int mid = (lo + hi) / 2;

            if (check(mid)) {
                leng = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        System.out.println(leng);

        sc.close();
    }
}
