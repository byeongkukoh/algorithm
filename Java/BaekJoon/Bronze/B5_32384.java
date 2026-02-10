import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        String str = "LoveisKoreaUniversity";

        for (int i = 0; i < N; i++) {
            System.out.print(str + " ");
        }
    }
}