/**
 * Name: Sqrt root Double
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

double mySqrt(double n) {
    if(n == 0) {
    	return 0;
    }

    if(n < 0) {
    	return -1;
    }

    double low = 0, high = n, mid;

    for(int i = 0; i < 100; i++) {
    	mid = low + (high - low) / 2;

    	if(mid * mid < n) {
    		low = mid;
    	} else {
    		high = mid;
    	}
    }

    return mid;
}

int main()
{
	double n;

	cin >> n;
	cout << mySqrt(n) << endl;

	return 0;
}