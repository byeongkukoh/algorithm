import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int answer = 0;
        int tired = 0;

        for (int t = 0; t < 24; t++) {
            // 일을 할 수 있는 경우
            if (tired + A <= M) {
                tired = tired + A;
                answer = answer + B;
            }
            // 일을 할 수 없는 경우
            else {
                tired = Math.max(0, tired - C);
            }
        }

        System.out.println(answer);
    }
}
