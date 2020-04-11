/** 
 * Name: Floating Point Power  
 * Author Name: Sourab Hossain
 */

#include "bits/stdc++.h"

using namespace std;

double power(double p, int n) {
    if(n == 0) {
        return 1.0;
    }

    double half = pow(p, n / 2);

    if(!(n & 1)) {
       return half * half;  
    }
    
    if(n > 0) {
        return half * half * p;
    } 
    
    return half * half / p;
}

int main(int argc, char const *argv[])
{
	double p;
	int q;

	cin >> p >> q;
	cout << power(p, q) << endl;
	
	return 0;
}