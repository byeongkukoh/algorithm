#include <bitset>
#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> month_map;

void month_init() {
  month_map["January"] = 1;
  month_map["February"] = 2;
  month_map["March"] = 3;
  month_map["April"] = 4;
  month_map["May"] = 5;
  month_map["June"] = 6;
  month_map["July"] = 7;
  month_map["August"] = 8;
  month_map["September"] = 9;
  month_map["October"] = 10;
  month_map["November"] = 11;
  month_map["December"] = 12;
}

int temp_parsing(string temp) {
  int ch = 0;

  temp[temp.size() - 1] = ' ';

  ch = stoi(temp);

  return ch;
}

int time_parsing(string temp, string type) {
  if (type == "hour") {
    string t = "";
    for (int i = 0; temp[i] != ':'; i++) {
      t += temp[i];
    }

    return stoi(t);
  }

  if (type == "min") {
    string t = "";
    for (int i = temp.find(':') + 1; temp[i] != 'a' && temp[i] != 'p'; i++) {
      t += temp[i];
    }

    return stoi(t);
  }

  if (type == "ampm") {
    if (temp.find("a") != -1) {
      return 1;
    }

    if (temp.find("p") != -1) {
      return 2;
    }
  }

  if (type == "time") {
    string t = "";
    for (int i = 0; temp[i] != 'm'; i++) {
      t += temp[i];
    }

    return stoi(t);
  }

  return -1;
}

int main() {
  month_init();

  string str;
  while (getline(cin, str)) {
    string temp[6];

    int i = 0;
    int eidx = 0;
    for (int sidx = str.find(" "); sidx != str.size(); sidx = eidx) {
      eidx = str.find(" ", sidx + 1);

      if (eidx == -1) {
        eidx = str.size();
      }

      temp[i] = str.substr(sidx + 1, eidx - sidx);
      i++;
    }

    int ch = temp_parsing(temp[0]);
    int mo = month_map[temp[1].substr(0, temp[1].size() - 1)];
    int d = stoi(temp[2]);
    int y = temp_parsing(temp[3]);
    int h = time_parsing(temp[4], "hour");
    int m = time_parsing(temp[4], "min");
    int tp = time_parsing(temp[4], "ampm");
    int t = time_parsing(temp[5], "time");

    bitset<32> res;

    bitset<32> year(y - 1994);
    res |= year;

    bitset<32> channel(ch);
    res = (res << 6) | channel;

    bitset<32> month(mo);
    res = (res << 4) | month;

    bitset<32> day(d);
    res = (res << 5) | day;

    int s = 0;
    if (h == 12) {
      s = 0;

      if (m == 30) {
        s += 1;
      }
    } else {
      s = h * 2;
      if (m == 30) {
        s += 1;
      }
    }

    if (tp == 2) {
      s += 24;
    }

    bitset<32> start(s);
    res = (res << 6) | start;

    bitset<32> plen(t / 30);
    res = (res << 4) | plen;

    cout << res.to_ullong() << "\n";
  }

  return 0;
}