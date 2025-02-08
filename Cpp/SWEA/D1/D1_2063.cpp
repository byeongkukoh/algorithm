// #include <stdio.h>
// #include <algorithm>

// int main()
// {
//     int n;
//     scanf("%d", &n);

//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }

//     std::sort(arr, arr + n);

//     printf("%d", arr[n / 2]);

//     return 0;
// }

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> vect;
  vect.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> vect[i];
  }

  sort(vect.begin(), vect.end());

  cout << vect[N / 2];

  return 0;
}