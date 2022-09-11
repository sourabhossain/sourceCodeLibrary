/**
 * Name: Sqrt root Double
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

double sqrtPrecision(double squareRoot, int n, int p) {
    double decimalValue = 0.1;
    
    for(int i = 0; i < p; i++) {
        while(squareRoot * squareRoot <= n) {
            squareRoot = squareRoot + decimalValue;
        }
        
        squareRoot = squareRoot - decimalValue;
        decimalValue = decimalValue / 10;
    }
    
    return squareRoot;
}

double findSquareRoot(int n, int p) {
    if(n <= 1) {
        return n;
    }
    
    int low = 1, high = n;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(mid * mid <= n && (mid + 1) * (mid + 1) > n) {
            return sqrtPrecision((double)mid, n, p);
        }
        
        if(mid * mid <= n) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return sqrtPrecision(high, n, p);
}

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
