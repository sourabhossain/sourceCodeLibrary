/** 
 * Name: Binary Search
 * Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector <int> &data, int target) {
	int length = data.size();

	if(length == 0) {
		return -1;
	}
    
    int left = 0, right = length, mid;

    while(left <= right) {
    	mid = left + (right - left) / 2;

    	if(data[mid] == target) {
    		return mid;
    	}

    	if(data[mid] < target) {
    		left = mid + 1;
    	} else {
    		right = mid - 1;
    	}
    }

	return -1;
} // end binarySearch function

int main()
{
    int length, target;
    
    scanf("%d%d", &length, &target);
    vector <int> data(length);
    
    for(int i = 0; i < length; i++) {
        scanf("%d", &data[i]);
    }
    
    sort(data.begin(), data.end());

    printf("%d\n", binarySearch(data, target)); // go to binarySearch function
    
	return 0;
}