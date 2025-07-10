package BaekJoon.Silver;

import java.util.Scanner;

public class S2_1541 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String str = sc.nextLine();

        boolean isM = false;
        String temp = "";
        long sum1 = 0;
        long sum2 = 0;

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);

            if (ch >= '0' && ch <= '9') {
                temp += ch;
            } else if (!isM && (ch == '+' || ch == '-')) {
                if (ch == '-') isM = true;

                sum1 += Integer.parseInt(temp);
                temp = "";
            } else if (isM && (ch == '+' || ch == '-')) {
                sum2 += Integer.parseInt(temp);
                temp = "";
            }
        } 

        if (isM) {
            System.out.println(sum1 - sum2 - Integer.parseInt(temp));
        } else {
            System.out.println(sum1 + Integer.parseInt(temp));
        }

        sc.close();
    }
}
