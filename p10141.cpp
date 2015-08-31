#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
 //uses c++11 properties
struct Proposal{
  string name;
  float price;
  float req;
  int i;
};

/*int main(int argc, char * argv[]) {
  int n,p,count = 1;
  string temp;
  Proposal prop;
  vector<string> results;
  while(scanf("%d %d",&n,&p) && (n||p)) {
    cin >> ws;//remove \n or whitespace trailing after previous cin
    for(int i = 0; i < n; i++) {
      getline(cin,temp);
    }
    vector<Proposal> proposals;
    for(int j = 0; j < p; j++) {
      prop.i = j;
      cin >> prop.name >> prop.price >> prop.req;
      cin>>ws; //remove \n or whitespace trailing after previous cin
      for(int i = 0; i < prop.req; i++) {
        getline(cin,temp);
      }
      proposals.push_back(prop);
    }
    //processing
    Proposal maxProp,currentProp;
    maxProp.price = -1.0;
    maxProp.req = -1;
    int max = -1, comp;
    for(int i = 0; i < proposals.size(); i++) {
      currentProp = proposals[i];
      comp = currentProp.req / n;
      if(comp > max) {
        maxProp = currentProp;
        max = comp;
      }
      else if(comp == max) {
        if(currentProp.price > maxProp.price) {
          maxProp = currentProp;
          max = comp;
        }
        else if(currentProp.price == maxProp.price)
          if(currentProp.i < maxProp.i) {
            maxProp = currentProp;
            max = comp;
          }
      }
    }
    results.push_back("RFP #"+to_string(count)+"\n"+maxProp.name);
    count++;
  }
  for(int i = 0; i < results.size(); i++) {
    if(i == results.size()-1)
      cout << results[i] +"\n";
    else
      cout << results[i]+"\n\n";
  }
  return 0;
}*/
int main(int argc, char * argv[]) {
  int p,count = 1;float max,comp, n;
  string temp;
  Proposal prop,maxProp;
  vector<string> results;
  while(scanf("%f %d",&n,&p) && (n||p)) {
    cin >> ws;//remove \n or whitespace trailing after previous cin
    for(int i = 0; i < n; i++) {
      getline(cin,temp);
    }
    max=-1;
    maxProp.price = -1;
    maxProp.req = -1;
    //input
    for(int j = 0; j < p; j++) {
      prop.i = j;
      cin >> ws;
      getline(cin,prop.name);
      cin >> prop.price >> prop.req;
      cin>>ws; //remove \n or whitespace trailing after previous cin
      for(int i = 0; i < prop.req; i++) {
        getline(cin,temp);
      }
      //processing
      comp = prop.req / n;
      if(comp > max) {
        maxProp = prop;
        max = comp;
      }
      else if(comp == max) {
        if(prop.price < maxProp.price) {
          maxProp = prop;
        }
        else if(prop.price == maxProp.price)
          if(prop.i < maxProp.i) {
            maxProp = prop;
          }
      }
    }
      results.push_back("RFP #"+to_string(count)+"\n"+maxProp.name+"\n");
      count++;
    }
    for(int i = 0; i < results.size(); i++) {
      if(i == results.size()-1)
        cout << results[i];
      else
        cout << results[i] << endl;
    }
  return 0;
}
