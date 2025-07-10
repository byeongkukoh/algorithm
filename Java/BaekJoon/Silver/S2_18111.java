package BaekJoon.Silver;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class S2_18111 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        int[] ground = new int[n * m];

        int min_value = 256;
        int max_value = 0;
        int idx = 0;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 0; j < m; j++) {
                ground[idx] = Integer.parseInt(st.nextToken());

                if (ground[idx] > max_value) max_value = ground[idx];

                if (ground[idx] < min_value) min_value = ground[idx];

                idx++;
            }
        }

        int height = 0;
        int ansTime = Integer.MAX_VALUE;

        for (int target = min_value; target <= max_value; target++) {
            int dig = 0;
            int ins = 0;

            for (int i = 0; i < n * m; i++) {
                if (ground[i] > target) {
                    dig += (ground[i] - target);
                } else {
                    ins += (target - ground[i]);
                }
            }

            int tempTime = dig * 2 + ins * 1;

            if ((tempTime <= ansTime) && (dig + b - ins >= 0)) {
                height = target;
                ansTime = tempTime;
            }
        }

        System.out.printf("%d %d", ansTime, height);
    }
}
