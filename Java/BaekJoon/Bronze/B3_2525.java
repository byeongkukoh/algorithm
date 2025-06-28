package BaekJoon.Bronze;

import java.util.Scanner;

public class B3_2525 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int hour = sc.nextInt();
        int min = sc.nextInt();

        int time = sc.nextInt();

        int temp = min + time;

        hour = (hour + (temp / 60)) % 24;
        min = temp % 60;

        System.out.println(hour + " " + min);

        sc.close();
    }
}
