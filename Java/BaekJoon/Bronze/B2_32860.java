package BaekJoon.Bronze;

import java.util.Scanner;

public class B2_32860 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int year = sc.nextInt();
        int number = sc.nextInt();

        System.out.print("SN ");
        System.out.print(year);

        if (number < 27) {
            System.out.print((char)(number + 64));
        } else {
            int q = (number - 1) / 26;
            int r = (number - 1) % 26;

            System.out.print((char)('a' + q - 1));
            System.out.print((char)('a' + r));
        }

        sc.close();
    }
}
