package BaekJoon.Bronze;

import java.util.*;

public class B1_1110 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int number = sc.nextInt();

        int origin = number;
        int cycle = 0;

        while(true) {
            cycle++;
            int result = 0;
            result += number / 10;
            number = number % 10;

            result += number;

            int temp = number * 10 + result % 10;

            if (temp == origin) break;

            number = temp;
        }

        System.out.println(cycle);

        sc.close();
    }
}
