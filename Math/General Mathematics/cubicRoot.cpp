/** 
 * Name: Cubic Root  
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>
#define CUBIC(n) (n * n * n)

using namespace std;

double different(double n, double mid) {
	double cubic = CUBIC(mid);

	if(n > cubic) {
		return n - cubic;
	} else {
		return cubic - n;
	}
}

double cubicRoot(double n) {
	double start = 0, end = n;

	while(true) {
		double mid = start + (end - start) / 2;

		if(different(n, mid) <= 0.0000001) {
			return mid;
		}

		if(CUBIC(mid) > n) {
			end = mid;
		} else {
			start = mid;
		}
	}
}

int main(int argc, char const *argv[])
{
	double n;
    
    while(cin >> n) {
    	cout << cubicRoot(n) << endl;
    }
    
    return 0;
}