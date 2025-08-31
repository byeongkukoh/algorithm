package BaekJoon.Bronze;

import java.util.Scanner;

public class B4_16486 {
    final static double PI = 3.141592;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        double d1 = sc.nextDouble();
        double d2 = sc.nextDouble();

        double line = (d1 * 2) + (2 * PI * d2);

        System.out.println(line);

        sc.close();

    }
}
