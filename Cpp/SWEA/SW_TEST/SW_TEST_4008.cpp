#include <climits>
#include <iostream>

using namespace std;

int numbers[12] = {0};
int used[12] = {0};
int pick[12] = {0};
int opts[4] = {0};  // + - * /

int N;
int MAX = INT_MIN, MIN = INT_MAX;

void func(int now) {
  if (now == N - 1) {
    int res = numbers[0];

    for (int i = 0; i < N - 1; i++) {
      if (pick[i] == 0) {
        res += numbers[i + 1];
      } else if (pick[i] == 1) {
        res -= numbers[i + 1];
      } else if (pick[i] == 2) {
        res *= numbers[i + 1];
      } else {
        res /= numbers[i + 1];
      }
    }

    if (res > MAX) MAX = res;
    if (res < MIN) MIN = res;
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (opts[i] == 0) continue;

    pick[now] = i;
    opts[i]--;

    func(now + 1);

    pick[now] = 0;
    opts[i]++;
  }
}

int main() {
  int test;
  cin >> test;

  for (int t = 1; t <= test; t++) {
    MAX = INT_MIN;
    MIN = INT_MAX;

    cin >> N;

    // 연산자 카드 개수
    for (int i = 0; i < 4; i++) {
      cin >> opts[i];
    }

    // 숫자
    for (int i = 0; i < N; i++) {
      cin >> numbers[i];
    }

    func(0);

    cout << "#" << t << " " << MAX - MIN << "\n";
  }

  return 0;
}

// #include <climits>
// #include <iostream>

// using namespace std;

// // char operators[4] = { '+', '-', '*', '/' };
// int operation[12] = {0};
// int numbers[12] = {0};
// int used[12] = {0};
// int pick[12] = {0};

// int N;
// int MAX = INT_MIN, MIN = INT_MAX;

// void func(int now) {
//   if (now == N - 1) {
//     int res = numbers[0];

//     for (int i = 0; i < N - 1; i++) {
//       if (pick[i] == 0) {
//         res += numbers[i + 1];
//       } else if (pick[i] == 1) {
//         res -= numbers[i + 1];
//       } else if (pick[i] == 2) {
//         res *= numbers[i + 1];
//       } else {
//         res /= numbers[i + 1];
//       }
//     }

//     if (res > MAX) MAX = res;
//     if (res < MIN) MIN = res;
//     // cout << res << " ";
//     return;
//   }

//   for (int i = 0; i < N - 1; i++) {
//     if (used[i] == 1) continue;

//     pick[now] = operation[i];
//     used[i] = 1;

//     func(now + 1);

//     pick[now] = 0;
//     used[i] = 0;
//   }
// }

// int main() {
//   int test;
//   cin >> test;

//   for (int t = 1; t <= test; t++) {
//     MAX = INT_MIN;
//     MIN = INT_MAX;

//     cin >> N;

//     // 연산자 카드 개수
//     int opts[4] = {0};
//     for (int i = 0; i < 4; i++) {
//       cin >> opts[i];
//     }

//     // 숫자
//     for (int i = 0; i < N; i++) {
//       cin >> numbers[i];
//     }

//     // 연산자 배열(인덱스)로 변환
//     int idx = 0;
//     for (int i = 0; i < 4; i++) {
//       while (opts[i] > 0) {
//         operation[idx] = i;
//         idx++;
//         opts[i]--;
//       }
//     }

//     func(0);

//     cout << "#" << t << " " << MAX - MIN << "\n";
//   }

//   return 0;
// }