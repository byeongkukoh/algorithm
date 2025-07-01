package BaekJoon.Bronze;

import java.util.Scanner;

public class B4_25625 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int x = sc.nextInt();
        int y = sc.nextInt();

        if (y >= x) {
            System.out.println(y - x);
        } else {
            System.out.println(x + y);
        }

        sc.close();
    }
}