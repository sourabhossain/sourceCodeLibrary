/**
 *  Name: Lower Bound Searching
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int lowerBound(vector<int>& data, int target) {
    int left = 0, right = data.size() - 1, mid, index = -1;

    while(left <= right) {
    	mid = left + (right - left) / 2;
        
        if(data[mid] == target) {
            index = mid;
            right = mid - 1;
        } else if(data[mid] < target) {
    		left = mid + 1;
    	} else {
    		right = mid - 1;
    	}
    }	

    return index;
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

	cout << lowerBound(data, target) << endl;

	return 0;
}