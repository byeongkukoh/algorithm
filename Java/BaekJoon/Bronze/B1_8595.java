package BaekJoon.Bronze;

import java.util.Scanner;

public class B1_8595 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        String str = sc.next();

        long result = 0;
        String temp = "";

        for (int i = 0; i < n; i++) {
            char ch = str.charAt(i);
            
            if (ch >= '0' && ch <= '9') {
                temp += ch;
            } else {
                if (!temp.equals("")) {
                    result += Integer.parseInt(temp);
                    temp = "";
                }
            }
        }

        if (!temp.equals("")) {
            result += Integer.parseInt(temp);
        }

        System.out.println(result);

        sc.close();
    }
}
