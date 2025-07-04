package BaekJoon.Bronze;

import java.util.Scanner;

public class B5_2420 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long n = sc.nextLong();
        long m = sc.nextLong();

        long res = n - m;

        if (res < 0) System.out.println(-res);
        else System.out.println(res);
        
        sc.close();
    } 
}
