/** 
 * Name: GCD Of Floating Point  
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

double gcd(double a, double b) {
	if(a < b) {
		return gcd(b, a);
	}

	if(fabs(b) < 0.0001) {
		return a;
	} else {
		return gcd(b, a - floor(a / b) * b);
	}
}

int main(int argc, char const *argv[])
{
	double a, b;

	scanf("%lf%lf", &a, &b);
	printf("%0.2lf\n", gcd(a, b));
    
    return 0;
}