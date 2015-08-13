#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;



int main(int argc, char * argv[]) {

  int n,m,c,seq = 0;
  while(scanf("%d %d %d",&n,&m,&c),n != 0 && m != 0 && c != 0){ //3 6 10
    seq++;
    vector<int> devices(n), status(n); //need to use two vectors since no capability for multiple elements
    for(int i = 0; i < n; i++) {
      int inp;
      scanf("%d",&inp);
      devices[i] = inp; //2 5 7
      status[i] = 0;
    }
    int key,powSum = 0,max = -1;
    for(int i = 0; i < m; i++) {
      int sw;
      scanf("%d",&sw);
      key = devices[sw-1]; //5
      status[sw-1] = 1 - status[sw-1]; //toggle the status of the device
      if(status[sw-1] == 1) {
        powSum += key; //5
        if(powSum > max)
          max = powSum;
      }
      else
        powSum -= key;
    }
    int sum = 0;
    for(int i = 0; i < n; i++) {
      if(status[i] == 1)
        sum += devices[i];
    }
    printf("Sequence %d\n",seq);
    if(max > c) {
      printf("Fuse was blown.\n");
    }
    else{
      printf("Fuse was not blown.\n");
      printf("Maximal power consumption was %d amperes.\n",max);
    }
    printf("\n");
  }
  return 0;
}
