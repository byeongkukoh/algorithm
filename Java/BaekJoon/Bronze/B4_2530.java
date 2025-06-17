package BaekJoon.Bronze;

import java.util.Scanner;

public class B4_2530 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int hour = sc.nextInt();
        int minute = sc.nextInt();
        int second = sc.nextInt();

        int time = sc.nextInt();

        int spendHour = time / 3600;
        int spendMin = (time % 3600) / 60;
        int spendSec = (time % 3600) % 60;

        hour += spendHour;
        minute += spendMin;
        second += spendSec;

        if (second >= 60) {
            second -= 60;
            minute += 1;
        }

        if (minute >= 60) {
            minute -= 60;
            hour += 1;
        }

        if (hour >= 24) {
            hour %= 24;
        }

        System.out.print(hour);
        System.out.print(" ");
        System.out.print(minute);
        System.out.print(" ");
        System.out.print(second);

        sc.close();
    }
}
