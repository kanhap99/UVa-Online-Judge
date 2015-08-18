#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


char mapChar(char c) {
  switch(c) {
    case 'B': case 'P': case 'F': case 'V': return '1';
    case 'C': case 'S': case 'K':  case 'G': case 'J': case 'Q': case 'X': case 'Z': return '2';
    case 'D':  case 'T':  return '3';
    case 'L':  return '4';
    case 'M':  case 'N':  return '5';
    case 'R':  return '6';
    default: return '0';
  }
}
//SCHAAK
int main(int argc, char * argv[]) {

  string s,code="";
  vector<string> names,soundex;
  names.push_back("NAME");
  soundex.push_back("SOUNDEX CODE");
  char current;

  while(getline(cin,s)) {
    code = "";
    current = 'a';
    names.push_back(s);
  //code processing
  code += s[0];//s
  for(int i = 1; i < s.size(); i++) {
    current = mapChar(s[i]); //c
    if(!(mapChar(s[i]) == mapChar(s[i-1])) && !(current == '0'))
      code += current;
  }
  //modifications
  if(code.size() < 4) {
    int zeros = 4-code.size();
    for(int i = 1; i <= zeros; i++)
      code += '0';
  }
  if(code.size() > 4)
    code = code.substr(0,4);

  //adding to map
  soundex.push_back(code);
}
  int len = 0;
  for(int i = 0; i < names.size(); i++) {
    for(int j = 0; j < 9; j++)
      cout << " ";
    cout << names[i];
    len = 25 - names[i].size();
    for(int k = 0; k < len; k++)
      cout << " ";
    cout << soundex[i] << endl;
  }
  for(int i = 0; i < 19; i++)
    cout << " ";
  cout << "END OF OUTPUT" << endl;

  return 0;
}
