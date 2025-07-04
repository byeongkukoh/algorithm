package BaekJoon.Bronze;

import java.util.Scanner;

public class B3_10872 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        long res = 1;
        for (int i = 1; i <= n; i++) {
            res *= i;
        }

        System.out.println(res);

        sc.close();
    }
}
