#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct ID{
  int base;
  int size;
  int d;
  vector<int> lowers;
  vector<int> uppers;
  vector<int> C;
  int c;
};
vector<int> calculateC(int d,int size,vector<int> u, vector<int> l) {
  vector<int> C(d);
  C[d-1] = size;
  for(int i = d-2; i >= 0; i--) {
    C[i] = C[i+1] * (u[i+1] - l[i+1] + 1);
  }
  return C;
}
int calculatec(int base,int d,vector<int> C, vector<int> l) {
  int c = base;
  for(int i = 0; i < d; i++) {
    c  -= (C[i]*l[i]);
  }
  return c;
}
/*int getAddress(ID id,vector<int> I) {
  int c = calculatec(id);
  for(int i = 0; i < I.size(); i++) {
    c += calculateC(id,i+1)*I[i];
  }
  return c;
}*/
int getAddress(int c, vector<int> C, vector<int> I) {
  int address = c;
  for(int i = 0; i < I.size(); i++) {
    address += C[i]*I[i];
  }
  return address;
}
int main(int argc, char * argv[]) {
  int n,r;
  map<string,ID> ref;
  scanf("%d %d\n",&n,&r);
  for(int i = 0; i < n; i++) {
    string s;
    ID id;
    cin >> s >> id.base >> id.size >> id.d;
    for(int i = 0; i < id.d; i++) {
      int l,u;
      cin >> l >> u;
      id.lowers.push_back(l);
      id.uppers.push_back(u);
    }
    id.C = calculateC(id.d,id.size,id.uppers,id.lowers);
    id.c = calculatec(id.base,id.d,id.C,id.lowers);
    ref.insert(make_pair(s,id));
  }

  for(int i = 0; i < r; i++) {
    string s;
    cin >> s;
    ID id = ref[s];
    vector<int> I(id.d);
    //taking array references
    cout << s << "[";
    for(int i = 0; i < I.size(); i++) {
      int x;
      cin >> x;
      I[i] = x;
      if(i != I.size() - 1)
        cout << x << ", ";
      else
        cout << x;
    }
    /*Output*/
    int add = getAddress(id.c,id.C,I);
    cout << "] = " << add << endl;
  }

  /*output*/
  return 0;
}
