package BaekJoon.Bronze;

import java.io.*;
import java.util.*;

public class B3_14920 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int C = Integer.parseInt(br.readLine());
        int n = 1;

        while (C != 1) {
            n++;

            if (C % 2 == 0)
                C = C / 2;
            else
                C = 3 * C + 1;
        }

        System.out.println(n);
    }
}
