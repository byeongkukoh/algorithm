import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int i = 0; i < 3; i++) {
            int N = Integer.parseInt(br.readLine());

            BigInteger sum = new BigInteger("0");
            for (int j = 0; j < N; j++) {
                String temp = br.readLine();
                BigInteger temp2 = new BigInteger(temp);

                sum = sum.add(temp2);
            }

            int result = sum.compareTo(new BigInteger("0"));
            if (result < 0) {
                System.out.println("-");
            } else if (result > 0) {
                System.out.println("+");
            } else {
                System.out.println("0");
            }
        }
    }
}