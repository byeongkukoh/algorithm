package BaekJoon.Gold;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class COIN {
    long cost;
    long cnt;

    public COIN(long cost, long cnt) {
        this.cost = cost;
        this.cnt = cnt;
    }
}

public class G3_2177 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        long C = sc.nextLong();

        COIN[] coins = new COIN[N];

        for (int i = 0; i < N; i++) {
            long cost = sc.nextLong();
            long cnt = sc.nextLong();

            coins[i] = new COIN(cost, cnt);
        }

        Arrays.sort(coins, new Comparator<COIN>() {
            @Override
            public int compare(COIN left, COIN right) {
                return Long.compare(right.cost, left.cost);
            }
        });

        long ans = 0;

        while(true) {
            long pay = C;
            
            // 최저 급료 정확하게 지급
            for (int i = 0; i < N; i++) {
                if (pay < coins[i].cost) continue;

                long use = Math.min(coins[i].cnt, pay / coins[i].cost);

                pay = pay - coins[i].cost * use;
                coins[i].cnt -= use;
            }

            // 최저 급료 초과 지급
            if (pay > 0) {
                boolean overpay = false;
                for (int i = N - 1; i >= 0; i--) {
                    if (coins[i].cnt > 0) {
                        pay = pay - coins[i].cost;
                        coins[i].cnt -= 1;

                        overpay = true;
                        break;
                    }
                }

                if (!overpay) break;
            }

            ans++;
        }

        System.out.println(ans);

        sc.close();
    }
}