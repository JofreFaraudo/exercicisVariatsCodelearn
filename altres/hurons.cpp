#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int k, n , c, a = 0;
	cin >> k >> n;
	for(int i = 0; i < k; i++){
		cin >> a;
		c += a;
	}
	c = floor(c/n);
	cout << c;
	return 0;
}
