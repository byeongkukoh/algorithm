package BaekJoon.Bronze;

import java.io.*;
import java.util.*;

public class B4_19698 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int W = Integer.parseInt(st.nextToken());
        int H = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());

        int width = W / L;
        int height = H / L;

        int pos = width * height;

        if (pos < N) {
            System.out.println(pos);
        } else {
            System.out.println(N);
        }
    }
}
