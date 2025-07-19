package BaekJoon.Gold;

import java.util.Scanner;

public class G1_1300 {
    static boolean check(long N, long k, long x) {
        long cnt = 0;

        for (int i = 1; i <= N; i++) {
            cnt += Math.min(N, x / i);
        }

        if (cnt >= k) return true;

        return false;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long N = sc.nextLong();
        long k = sc.nextLong();

        long lo = 1;
        long hi = N * N;

        long ans = 0;

        while(lo <= hi) {
            long mid = (lo + hi) / 2;

            if (check(N, k, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        System.out.println(ans);
        
        sc.close();
    }
}
