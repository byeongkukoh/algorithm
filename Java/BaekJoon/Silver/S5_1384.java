import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int groupNumber = 1;
        while(true) {
            int n = Integer.parseInt(br.readLine());

            // 반복문 종료 조건 = 입력이 0일 때,
            if (n == 0) break;

            // 그룹 정보 입력
            String[] group = new String[n];
            String[][] group_info = new String[n][n - 1];

            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                String name = st.nextToken();
                group[i] = name;

                for (int j = 0; j < n - 1; j++) {
                    String info = st.nextToken();
                    group_info[i][j] = info;
                }
            }

            System.out.println("Group " + groupNumber);
            boolean isNasty = false;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n - 1; j++) {
                    if (group_info[i][j].equals("X")) continue;

                    if (group_info[i][j].equals("N")) {
                        isNasty = true;
                        System.out.println(group[(i - j - 1 + n) % n] + " was nasty about " + group[i]);
                    }
                }
            }

            if (!isNasty) {
                System.out.println("Nobody was nasty");
            }

            groupNumber++;

            System.out.println();
        }
    }
}
