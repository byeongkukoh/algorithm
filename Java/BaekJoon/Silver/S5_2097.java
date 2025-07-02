package BaekJoon.Silver;

import java.util.Scanner;

public class S5_2097 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        if (n == 1 || n == 2) {
            System.out.println(4);
        } else {
            int root = (int)Math.round(Math.sqrt(n));

            if (root * root >= n) {
                System.out.println((root - 1) * 4);
            } else {
                System.out.println((root - 1) * 2 + root * 2);
            }
        }
        
        sc.close();
    }
}
