package BaekJoon.Gold;

import java.util.Arrays;
import java.util.Scanner;

public class G5_3079 {

    public static int N, M;
    public static long[] timeList = new long[100000];

    public static boolean check(long timeVal) {
        long person = 0;

        for (int i = 0; i < N; i++) {
            person += timeVal / timeList[i];

            if (person >= M) return true;
        }

        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();

        for (int i = 0; i < N; i++) {
            timeList[i] = sc.nextLong();
        }

        Arrays.sort(timeList, 0, N);

        long lo = 1;
        long hi = timeList[N - 1] * M;

        long ans = 0;

        while(lo <= hi) {
            long mid = (lo + hi) / 2;

            if (check(mid)) {
                hi = mid - 1;
                ans = mid;
            } else {
                lo = mid + 1;
            }
        }

        System.out.println(ans);

        sc.close();
    }
}