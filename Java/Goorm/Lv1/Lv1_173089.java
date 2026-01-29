package Java.Goorm.Lv1;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        StringTokenizer st = new StringTokenizer(input);

        String number = st.nextToken();

        int num_length = number.length();

        System.out.println(num_length);
    }
}