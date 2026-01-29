package Java.Goorm.Lv1;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        String K = st.nextToken();

        ArrayList<String> arr = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            String temp = st.nextToken();

            if (temp.contains(K))
                continue;

            arr.add(temp);
        }

        System.out.println(arr.size());
    }
}