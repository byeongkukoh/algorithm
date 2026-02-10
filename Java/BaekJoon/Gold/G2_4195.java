import java.io.*;
import java.util.*;

public class Main {
    static HashMap<String, String> friends;
    static HashMap<String, Integer> nums;

    public static String find(String f) {
        if (friends.get(f).equals(f)) return f;

        String root = find(friends.get(f));
        friends.put(f, root);

        return root;
    }

    public static void merge(String a, String b) {
        String f1 = find(a);
        String f2 = find(b);

        if (f1.equals(f2)) return;

        friends.put(f2, f1);

        nums.put(f1, nums.get(f1) + nums.get(f2));
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int test = Integer.parseInt(br.readLine());

        for (int t = 0; t < test; t++) {
            friends = new HashMap<>();
            nums = new HashMap<>();

            int F = Integer.parseInt(br.readLine());

            for (int f = 0; f < F; f++) {
                StringTokenizer st = new StringTokenizer(br.readLine());

                String temp1 = st.nextToken();
                String temp2 = st.nextToken();

                if (!friends.containsKey(temp1)) {
                    friends.put(temp1, temp1);
                    nums.put(temp1, 1);
                }

                if (!friends.containsKey(temp2)) {
                    friends.put(temp2, temp2);
                    nums.put(temp2, 1);
                }

                merge(temp1, temp2);

                int result = nums.get(find(temp1));
                System.out.println(result);
            }
        }
    }
}