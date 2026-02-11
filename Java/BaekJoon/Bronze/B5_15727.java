import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int L = Integer.parseInt(br.readLine());

        int answer = 0;
        for (int t = 5; t > 0; t--) {
            if (L == 0) break;

            answer += L / t;
            L = L % t;
        }

        System.out.println(answer);
    }
}
