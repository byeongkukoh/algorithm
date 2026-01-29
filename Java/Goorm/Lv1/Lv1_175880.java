package Java.Goorm.Lv1;

import java.io.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        Long result = 1L;
        for (Long i = 1L; i <= N; i++) {
            result = (result * i) % 1000000007L;
        }

        System.out.println(result);
    }
}