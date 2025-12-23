package BaekJoon.Gold;

import java.util.ArrayList;
import java.util.Scanner;

public class G5_1068 {
    static int n, skipNode;
    static int leapCount = 0;

    static ArrayList<ArrayList<Integer>> tree = new ArrayList<>();

    public static void checkLeap(int now) {
        if (now == skipNode) {
            return;
        }

        boolean hasChild = false;

        for (int i = 0; i < tree.get(now).size(); i++) {
            int next = tree.get(now).get(i);

            if (next == skipNode) {
                continue;
            }

            hasChild = true;
            checkLeap(next);
        }

        if (!hasChild) {
            leapCount++;
        }

        return;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();

        // 이중리스트 생성
        for (int i = 0; i < n; i++) {
            tree.add(new ArrayList<>());
        }

        int root = -1;

        // 부모노드 입력
        for (int i = 0; i < n; i++) {
            int parent = sc.nextInt();

            if (parent == -1) {
                root = i;
                continue;
            }

            tree.get(parent).add(i);
        }

        // 제외 노드 입력
        skipNode = sc.nextInt();

        // 리프 노드 탐색
        checkLeap(root);

        // 결과 출력
        System.out.println(leapCount);

        sc.close();
    }
}
