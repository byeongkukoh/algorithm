// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char n[5];
//     scanf("%s", &n);

//     int sum = 0;

//     for (int i = 0; i < strlen(n); i++)
//     {
//         sum += int(n[i] - '0');
//     }

//     printf("%d", sum);

//     return 0;
// }

// ====================================

#include <iostream>

using namespace std;

int main() {
  int number, sum = 0;
  cin >> number;

  while (number > 10) {
    sum += number % 10;
    number = number / 10;
  }

  sum += number;

  cout << sum;

  return 0;
}