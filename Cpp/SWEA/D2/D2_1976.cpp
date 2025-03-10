#include <iostream>

using namespace std;

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    int h1, m1;
    int h2, m2;

    cin >> h1 >> m1 >> h2 >> m2;

    int h_res = 0, m_res = 0;

    m_res = m1 + m2;
    if (m_res >= 60) {
      h_res = 1;
      m_res = m_res - 60;
    }

    h_res = h_res + h1 + h2;
    if (h_res > 12) h_res -= 12;

    cout << "#" << t + 1 << " " << h_res << " " << m_res << "\n";
  }

  return 0;
}