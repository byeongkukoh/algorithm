#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int l, c;

vector<char> vect;
int visited[20];
char path[20];

bool isVowel(char ch) {
  return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void func(int now, int vowels, int consonants) {
  if (now == l) {
    if (vowels >= 1 && consonants >= 2) {
      for (int i = 0; i < l; i++) {
        cout << path[i];
      }

      cout << "\n";
    }

    return;
  }

  for (int i = 0; i < vect.size(); i++) {
    if (visited[i] == 1) continue;
    if (now > 0 && path[now - 1] > vect[i]) continue;

    if (isVowel(vect[i])) {
      path[now] = vect[i];
      visited[i] = 1;

      func(now + 1, vowels + 1, consonants);
    } else {
      path[now] = vect[i];
      visited[i] = 1;

      func(now + 1, vowels, consonants + 1);
    }

    path[now] = ' ';
    visited[i] = 0;
  }
}

int main() {
  cin >> l >> c;

  for (int i = 0; i < c; i++) {
    char temp;
    cin >> temp;

    vect.push_back(temp);
  }

  sort(vect.begin(), vect.end());

  func(0, 0, 0);

  return 0;
}

// #include <algorithm>
// #include <iostream>
// #include <vector>

// using namespace std;

// int l, c;
// vector<char> vect;
// int visited[20];
// char path[20];
// int moreOne = 0;
// int moreTwo = 0;

// void func(int now) {
//   if (now == l) {
//     if (moreOne < 1 || moreTwo < 2) return;

//     for (int i = 0; i < l; i++) {
//       cout << path[i];
//     }
//     cout << "\n";

//     return;
//   }

//   for (int i = 0; i < vect.size(); i++) {
//     if (visited[i] == 1) continue;
//     if (now > 0 && path[now - 1] > vect[i]) continue;

//     if (vect[i] == 'a' || vect[i] == 'e' || vect[i] == 'i' || vect[i] == 'o'
//     ||
//         vect[i] == 'u') {
//       moreOne++;
//     } else {
//       moreTwo++;
//     }

//     path[now] = vect[i];
//     visited[i] = 1;

//     func(now + 1);

//     if (vect[i] == 'a' || vect[i] == 'e' || vect[i] == 'i' || vect[i] == 'o'
//     ||
//         vect[i] == 'u') {
//       moreOne--;
//     } else {
//       moreTwo--;
//     }

//     path[now] = ' ';
//     visited[i] = 0;
//   }
// }

// int main() {
//   cin >> l >> c;

//   for (int i = 0; i < c; i++) {
//     char temp;
//     cin >> temp;

//     vect.push_back(temp);
//   }

//   sort(vect.begin(), vect.end());

//   func(0);

//   return 0;
// }