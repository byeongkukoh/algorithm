package BaekJoon.Bronze;

import java.util.Scanner;

public class B5_34691 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            String str = sc.nextLine();

            if (str.compareTo("end") == 0) {
                break;
            } else if (str.compareTo("animal") == 0) {
                System.out.println("Panthera tigris");
            } else if (str.compareTo("tree") == 0) {
                System.out.println("Pinus densiflora");
            } else if (str.compareTo("flower") == 0) {
                System.out.println("Forsythia koreana");
            } else {
                break;
            }
        }

        sc.close();
    }
}
