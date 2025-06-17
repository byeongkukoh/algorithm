package BaekJoon.Bronze;

import java.util.Scanner;

public class B4_25704 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int cost = sc.nextInt();

        int result = cost;

        if (n >= 5) {
            if (result > cost - 500) {
                result = cost - 500;
            }
        }

        if (n >= 10) {
            if (result > cost * 9 / 10) {
                result = cost * 9 / 10;
            }
        }

        if (n >= 15) {
            if (result > cost - 2000) {
                result = cost - 2000;
            }
        }

        if (n >= 20) {
            if (result > cost * 3 / 4) {
                result = cost * 3 / 4;
            }
        }

        if (result < 0) {
            System.out.println(0);
        }
        else {
            System.out.println(result);
        }

        sc.close();

    }
}
