package BaekJoon.Bronze;

import java.util.Scanner;

public class B1_2851 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] arr = new int[10];

        for (int i = 0; i < 10; i++) {
            arr[i] = sc.nextInt();
        }

        int[] sumList = new int[10];

        sumList[0] = arr[0];
        int ans = sumList[0];

        for (int i = 1; i < 10; i++) {
            sumList[i] = sumList[i - 1] + arr[i];

            if (Math.abs(100 - sumList[i]) <= Math.abs(100 - ans)) {
                ans = sumList[i];
            }
        }

        System.out.println(ans);
        
        sc.close();
    }
}