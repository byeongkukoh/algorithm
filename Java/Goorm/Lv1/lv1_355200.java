package Java.Goorm.Lv1;

import java.io.*;
import java.util.*;

class Main {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        StringTokenizer st = new StringTokenizer(input);

        int AM = Integer.parseInt(st.nextToken());
        int CM = Integer.parseInt(st.nextToken());
        int BM = Integer.parseInt(st.nextToken());

        int now = 2;
        int gcd = 1;
        while (now <= AM && now <= CM * BM) {
            // 공약수이면
            if ((AM % now == 0) && ((CM * BM) % now == 0)) {
                gcd = now;
            }

            now++;
        }

        if (gcd == 1) {
            System.out.println((CM * BM) + " " + (AM));
        } else {
            System.out.println(((CM * BM) / gcd) + " " + (AM / gcd));
        }
    }
}