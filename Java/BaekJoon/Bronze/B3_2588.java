package BaekJoon.Bronze;

import java.util.Scanner;

public class B3_2588 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int b = sc.nextInt();

        int x = b / 100;
        int y = (b % 100) / 10;
        int z = ((b % 100) % 10);

        System.out.println(a * z);
        System.out.println(a * y);
        System.out.println(a * x);

        System.out.println(a * b);

        sc.close();
    }
}
