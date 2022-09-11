/**
 *  Name: Sqrt root Integer
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int mySqrt(int n) {
    if(n < 2) {
    	return n;
    }	

    int left = 1, right = n, mid, temp;

    while(left <= right) {
    	mid = left + (right - left) / 2;
    	temp = n / mid;

    	if(temp == mid) {
    		return mid;
    	} 

    	if(temp > mid) {
    		left = mid + 1;
    	} else {
    		right = mid - 1;
    	}
    }

    return right;
}

int findSquareRoot(int n) {
    if(n <= 1) {
        return n;
    }
    
    int low = 1, high = n;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(mid * mid <= n && (mid + 1) * (mid + 1) > n) {
            return mid;
        }
        
        if(mid * mid <= n) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return high;
}

int main()
{
	int n;

	cin >> n;
	cout << mySqrt(n) << endl;

	return 0;
}
