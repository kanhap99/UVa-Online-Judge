#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstddef>
using namespace std;

int main(int argc, char * argv[]) {

  string keyboard = "1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";
  vector<int> rows(4);
  rows[0] = 0;
  rows[1] = 12;
  rows[2] = 25;
  rows[3] = 36;
  string s;
  int pos = -1;
  while(getline(cin,s)){ //O S, GOMR YPFSU/
    for(int i = 0; i < s.size(); i++) {
      if(s[i] == ' '){
        cout << s[i];
        continue;
      }
      for(int j = 0; j < keyboard.size(); j++) { //linear search the char
        if(keyboard[j] == s[i]) {
          pos = j;
          break;
        }
      }
      if(binary_search(rows.begin(),rows.end(),pos))
          cout << s[i];
      else
          cout << keyboard[pos-1];
    }
    cout << endl;
}
  return 0;
}
