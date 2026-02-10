import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            double now = 0.0f;
            int time = Integer.parseInt(br.readLine());

            now = (now + time + 0.5) % 25;

            if (now >= 0 && now <= 17) System.out.println("ONLINE");
            else System.out.println("OFFLINE");
        }
    }
}