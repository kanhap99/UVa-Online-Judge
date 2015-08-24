#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long factorial(int f) {
	long fact = 1;
	for(int i = 1; i <= f; i++) {
		fact *= i;
	}
	return fact;
}
string permutation(string s, long n) {
	string res = "";
	while(n != 0) { //when it is the last character
		int k = (int) (n / factorial(s.size() - 1));
		long mod = n % factorial(s.size() -1);
		res = res + s[k];
		s.erase(s.begin() + k);
		n = mod;
	}
	return res + s;
}

int main(void) {

	long trials,n;
	cin >> trials;
	string input;
	while(trials--) {
		cin >> input >> n;
		sort(input.begin(), input.end());
		cout << permutation(input, n) << endl;
	}
	return 0;
}
