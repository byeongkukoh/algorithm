package BaekJoon.Bronze;

import java.util.Scanner;

public class B5_10807 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();

        int[] nums = new int[230];

        for (int i = 0; i < n; i++) {
            int temp = sc.nextInt();

            nums[temp + 100] += 1;
        }

        int res = sc.nextInt();

        System.out.println(nums[res + 100]);

        sc.close();
    }
    
}
