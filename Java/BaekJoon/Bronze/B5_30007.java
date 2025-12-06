package BaekJoon.Bronze;

import java.util.Scanner;

public class B5_30007 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int x = sc.nextInt();

            System.out.println(a * (x - 1) + b);
        }

        sc.close();
    }
}
