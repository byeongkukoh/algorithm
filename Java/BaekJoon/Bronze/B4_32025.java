import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int H = Integer.parseInt(br.readLine());
        int W = Integer.parseInt(br.readLine());

        if (H > W) {
            System.out.println(W * 50);
        } else {
            System.out.println(H * 50);
        }
    }
}
