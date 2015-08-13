#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//kanha   -->
string reverse(string s) {
  string r;
  for(int i = s.size()-1; i >= 0; i--) {
    r += s[i];
  }
  return r;
}
vector<string> &split(const string &s, char delim,vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}
vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}
int main(int argc, char * argv[]) {
  string s;
  vector<string> tokens;
  while(getline(cin,s)) {
    tokens = split(s,' ');
    for(int i = 0; i < tokens.size(); i++) {
      string r = reverse(tokens[i]);
      if(i == tokens.size() -1)
        cout << r;
      else
        cout << r << " ";
    }
    cout << endl;
}
  return 0;
}
