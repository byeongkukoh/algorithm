package BaekJoon.Bronze;

import java.util.Scanner;

public class B5_2742 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int num = sc.nextInt();

        while(num > 0) {
            System.out.println(num--);
        }

        sc.close();
    }
}
