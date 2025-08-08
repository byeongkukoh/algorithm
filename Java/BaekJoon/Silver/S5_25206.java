package BaekJoon.Silver;

import java.util.*;

public class S5_25206 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        HashMap<String, Double> score = new HashMap<String, Double>();
        score.put("A+", 4.5);
        score.put("A0", 4.0);
        score.put("B+", 3.5);
        score.put("B0", 3.0);
        score.put("C+", 2.5);
        score.put("C0", 2.0);
        score.put("D+", 1.5);
        score.put("D0", 1.0);
        score.put("F", 0.0);

        double total = 0.0;
        double total_cnt = 0.0;

        for (int i = 0; i < 20; i++) {
            String name = sc.next();
            double cnt = sc.nextDouble();
            String scr = sc.next();

            if (scr.equals("P")) continue;

            total += cnt * score.get(scr);
            total_cnt += cnt;

        }

        System.out.println(total / total_cnt);

        sc.close();
    }
}
