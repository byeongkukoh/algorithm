package BaekJoon.Bronze;

import java.util.Scanner;

public class B4_5524 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            String name = sc.next();

            System.out.println(name.toLowerCase());
        }

        sc.close();
    }
}
