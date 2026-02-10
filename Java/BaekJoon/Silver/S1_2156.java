import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int[] alcohol = new int[N];
        for (int i = 0; i < N; i++) {
            int temp = Integer.parseInt(br.readLine());

            alcohol[i] = temp;
        }

        int[] dp = new int[N];
        if (N >= 1) dp[0] = alcohol[0];
        if (N >= 2) dp[1] = Math.max(dp[0], alcohol[0] + alcohol[1]);
        if (N >= 3) dp[2] = Math.max(dp[1], Math.max(alcohol[0] + alcohol[2], alcohol[1] + alcohol[2]));

        for (int i = 3; i < N; i++) {
            dp[i] = Math.max(dp[i - 1], Math.max(dp[i - 2] + alcohol[i], dp[i - 3] + alcohol[i - 1] + alcohol[i]));
        }

        System.out.println(dp[N - 1]);
    }
}