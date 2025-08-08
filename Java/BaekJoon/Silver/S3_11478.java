package BaekJoon.Silver;

import java.util.*;

public class S3_11478 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String str = sc.next();
        HashMap<String, Integer> save = new HashMap<String, Integer>();

        int len = 1;
        while(len < str.length() + 1) {
            String temp = "";
            for (int i = 0; i < str.length(); i++) {
                if (i + len > str.length()) break;

                temp = str.substring(i, i + len);

                if (save.containsKey(temp)) continue;

                save.put(temp, 1);
            }

            len++;
        }

        System.out.println(save.size());

        sc.close();
    }
}
