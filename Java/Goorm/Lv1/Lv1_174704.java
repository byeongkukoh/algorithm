package Java.Goorm.Lv1;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        float a = Float.parseFloat(st.nextToken());
        float b = Float.parseFloat(st.nextToken());

        float result = a + b;

        System.out.printf("%.6f", result);
    }
}