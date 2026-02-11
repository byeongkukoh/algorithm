import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        if (N == 1) {
            System.out.print("*");
            return;
        }

        int total_count = 2 * N - 1;
        int start = total_count / 2;
        int end = total_count / 2;

        for (int row = 0; row < N; row++) {
            if (row == 0) {
                for (int j = 0; j < total_count; j++) {
                    if (j == start) {
                        System.out.print("*");
                        start = start - 1;
                        end = end + 1;
                        break;
                    } else {
                        System.out.print(" ");
                    }
                }

                System.out.println();
                continue;
            }

            if (start == 0) {
                for (int j = 0; j < total_count; j++) {
                    System.out.print("*");
                }

                System.out.println();
                continue;
            }

            for (int j = 0; j < total_count; j++) {
                if (j == start) {
                    System.out.print("*");
                    start = start - 1;
                    continue;
                }

                if (j == end) {
                    System.out.print("*");
                    end = end + 1;
                    break;
                }

                System.out.print(" ");
            }

            System.out.println();
        }
    }
}
