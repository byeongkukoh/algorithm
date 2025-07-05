package BaekJoon.Gold;

import java.util.Arrays;
import java.util.Scanner;

public class G4_2110 {
    public static int n, c;
    public static int[] house = new int[200000];

    public static boolean check(int dist) {
        int cnt = 1;
        int last = house[0];

        for (int i = 1; i < n; i++) {
            if (house[i] - last >= dist) {
                cnt++;
                last = house[i];
            }
        }

        if (cnt >= c) return true;
        else return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        c = sc.nextInt();

        for (int i = 0; i < n; i++) {
            int temp = sc.nextInt();

            house[i] = temp;
        }

        Arrays.sort(house, 0, n);

        int lo = 1;
        int hi = house[n - 1];

        int dist = 0;

        while(lo <= hi) {
            int mid = (hi + lo) / 2;

            if (check(mid)) {
                dist = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        System.out.println(dist);

        sc.close();
    }
}
