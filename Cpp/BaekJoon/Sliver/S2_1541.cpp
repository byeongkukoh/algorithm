#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;
  cin >> str;

  bool isM = false;

  string temp = "";

  long long sum = 0;
  long long sum2 = 0;

  for (int i = 0; i < str.size(); i++) {
    char ch = str[i];

    if (ch >= '0' && ch <= '9') {
      temp += ch;
      continue;
    }

    if (!isM && ch == '+') {
      sum += stoi(temp);
    } else if (!isM && ch == '-') {
      sum += stoi(temp);
      isM = true;
    } else {
      sum2 += stoi(temp);
    }

    temp = "";
  }

  if (isM) {
    cout << sum - sum2 - stoi(temp);
  } else {
    cout << sum + stoi(temp);
  }

  return 0;
}