/**
 *  Name: Sqrt root Integer
 *  Author Name: Sourav Hossain
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

int main()
{
	int n;

	cin >> n;
	cout << mySqrt(n) << endl;

	return 0;
}