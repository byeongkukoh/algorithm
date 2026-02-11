import java.io.*;
import java.util.*;

public class Main {
    static int[] parent = new int[51];
    static int[][] parties = new int[51][51];
    static int[] partyPeople = new int[51];

    public static int find(int a) {
        if (parent[a] == a) return parent[a];

        return parent[a] = find(parent[a]);
    }

    public static void merge(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return;
        if (pa > pb) {
            int temp = pb;
            pb = pa;
            pa = temp;
        }

        parent[pb] = parent[pa];
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N + 1; i++) {
            parent[i] = i;
        }

        st = new StringTokenizer(br.readLine());
        int truth = Integer.parseInt(st.nextToken());
        for (int i = 0; i < truth; i++) {
            int temp = Integer.parseInt(st.nextToken());

            parent[temp] = 0;
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());

            int cnt = Integer.parseInt(st.nextToken());
            partyPeople[i] = cnt;

            if (cnt > 0) {
                int temp = Integer.parseInt(st.nextToken());
                parties[i][0] = temp;

                for (int j = 1; j < cnt; j++) {
                    int temp2 = Integer.parseInt(st.nextToken());
                    parties[i][j] = temp2;

                    merge(temp, temp2);
                }
            }

        }

        int answer = M;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < partyPeople[i]; j++) {
                if (find(parties[i][j]) == 0) {
                    answer--;
                    break;
                }
            }
        }

        System.out.println(answer);
    }
}
