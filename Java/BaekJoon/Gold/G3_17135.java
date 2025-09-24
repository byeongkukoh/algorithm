package BaekJoon.Gold;

import java.util.Scanner;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

class Pos {
    public int y;
    public int x;

    public Pos(int y, int x) {
        this.y = y;
        this.x = x;
    }
}

class Node implements Comparable<Node> {
    public int row;
    public int col;
    public int dist;

    public Node(int row, int col, int dist) {
        this.row = row;
        this.col = col;
        this.dist = dist;
    }

    @Override
    public int compareTo(Node right) {
        if (this.dist != right.dist) return Integer.compare(this.dist, right.dist);

        if (this.col != right.col) return Integer.compare(this.col, right.col);

        return 0;
    }
}

public class G3_17135 {
    public static int N, M, D;
    public static int maxCount = 0;

    public static int[][] MAP;
    public static boolean[] checkLocation;

    public static int calculatorDist(int eY, int eX, int aY, int aX) {
        return Math.abs(eY - aY) + Math.abs(eX - aX);
    }

    public static int simulator() {
        int check = 0;
        int remainEnemyCount = 0;

        // 임시로 사용할 맵 정보 초기화
        int[][] tempMap;
        tempMap = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                tempMap[i][j] = MAP[i][j];

                if (tempMap[i][j] == 1) remainEnemyCount++; 
            }
        }

        // 궁수 위치
        Pos[] archers = new Pos[3];
        int idx = 0;
        for (int i = 0; i < M; i++) {
            if (checkLocation[i]) {
                archers[idx] = new Pos(N, i);

                idx++;
            }
        }

        // 시뮬레이션
        while(remainEnemyCount != 0) {
            Queue<Pos> killEnemy = new LinkedList<>();
            
            for (int i = 0; i < 3; i++) {
                Queue<Node> pque = new PriorityQueue<>();

                for (int row = 0; row < N; row++) {
                    for (int col = 0; col < M; col++) {
                        if (tempMap[row][col] == 1) {
                            int dist = calculatorDist(row, col, archers[i].y, archers[i].x);

                            if (dist <= D) {
                                pque.add(new Node(row, col, dist));
                            }
                        }
                    }
                }

                if (!pque.isEmpty()) {
                    Node temp = pque.peek();

                    killEnemy.add(new Pos(temp.row, temp.col));
                }
            }

            // 죽은 적 체크
            while(!killEnemy.isEmpty()) {
                Pos now = killEnemy.poll();

                if (tempMap[now.y][now.x] == 1) {
                    tempMap[now.y][now.x] = 0;

                    check++;
                    remainEnemyCount--;
                }
            }

            // 남은 적 이동
            for (int row = N - 1; row >= 0; row--) {
                for (int col = 0; col < M; col++) {
                    // 맵 끝에 도달한 적 체크
                    if (row == N - 1 && tempMap[row][col] == 1) {
                        tempMap[row][col] = 0;
                        remainEnemyCount--;

                        continue;
                    }

                    // 맵 끝에 도달하지 않은 경우
                    if (tempMap[row][col] == 1) {
                        tempMap[row][col] = 0;
                        tempMap[row + 1][col] = 1;
                    }
                }
            }
        }

        return check;
    }

    public static void locateArcher(int now, int start) {
        if (now == 3) {
            int check = simulator();

            if (check > maxCount) maxCount = check;

            return;
        }

        for (int i = start; i < M; i++) {
            if (checkLocation[i]) continue;

            checkLocation[i] = true;

            locateArcher(now + 1, i + 1);

            checkLocation[i] = false;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 기본 정보 입력
        N = sc.nextInt();
        M = sc.nextInt();
        D = sc.nextInt();

        // 맵 정보 입력
        MAP = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                MAP[i][j] = sc.nextInt();
            }
        }

        // 궁수 위치 정보 초기화
        checkLocation = new boolean[M];
        for (int i = 0; i < M; i++) {
            checkLocation[i] = false;
        }

        // 궁수 위치 배정
        locateArcher(0, 0);

        // 결과 출력
        System.out.println(maxCount);

        sc.close();
    }
}
