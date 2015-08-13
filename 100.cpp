#include <iostream>
#include <stdio.h>

using namespace std;

int getCycleLength(int n) {
  int count = 1;
  while(n != 1) {
    if(n%2 != 0)
      n = 3*n+1;
    else
      n = n/2;
    count++;
  }
  return count;
}

int main(int argc, char * argv[]) {

  int i,j;
  while(scanf("%d %d\n",&i,&j) == 2) {
    int max=-1;
    int iOrig = i,jOrig = j;
    if(i > j) {
      int temp = i;
      i = j;
      j = temp;
    }
    for(int index = i; index <= j; index++) {
      int c = getCycleLength(index);
      if(c > max)
        max = c;
    }
    cout << iOrig << " " << jOrig << " " << max << endl;
  }
  return 0;
}
