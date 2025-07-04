package BaekJoon.Bronze;

import java.util.Scanner;

public class B2_1568 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int count = 0;
        int now = 1;

        while(n != 0) {
            count++;
            if (n < now) now = 1;
            n = n - now;
            now++;
        }

        System.out.println(count);

        sc.close();
    }
}