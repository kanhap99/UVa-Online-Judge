#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char* argv[]) {
  float total,able,fall,per,dist,factor; //6,3,1,10
  int day;
      //loop of days
      /*All input working, now TODO is just recurring input and making edge cases!*/
    while(scanf("%f %f %f %f", &total, &able, &fall, &per), total || able || fall || per){
      dist = 0;
      factor = (per/100) * able;
      day = 0;
      do{
       day++;
        if(!(able < 0)) {
          dist += able;
          if(dist > total) {
            cout << "success on day " << day << endl;
            break;
          }
        }
        dist -= fall;
        if(dist < 0){
          cout << "failure on day "<<day <<endl;
          break;
        }
        able -= factor;
      }while(true);
  }
  return 0;
}
