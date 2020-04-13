/**
 *  Name: Upper Bound Searching
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int upperBound(vector<int>& data, int target) {
    int left = 0, right = data.size(), mid;

    while(left < right) {
        mid = left + (right - left) / 2;

        if(target >= data[mid]) {
            left = mid + 1; 
        } else {
            right = mid;
        }
    }

    return left;
}

int main()
{
	int n, target;

	scanf("%d%d", &n, &target);
	vector<int> data(n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}
    
    sort(data.begin(), data.end());

	cout << upperBound(data, target) << endl;

	return 0;
}