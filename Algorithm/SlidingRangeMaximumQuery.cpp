/**
 *  Name: Sliding Range Maximum Query
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

void SlidingRangeMaximumQuery(vector<int>& data, int length, int k) {
	deque<int> dq;
	int i;

	for(i = 0; i < k; i++) {
		while(!dq.empty() && data[i] >= data[dq.back()]) {
			dq.pop_back();
		}

		dq.push_back(i);
	}

	while(i < length) {
		cout << data[dq.front()] << " ";
        
        while(!dq.empty() && dq.front() <= i - k) {
        	dq.pop_front();
        }

		while(!dq.empty() && data[i] >= data[dq.back()]) {
			dq.pop_back();
		}

		dq.push_back(i++);
	}

	cout << data[dq.front()] << endl;
}

int main()
{
	int length, k;

	cin >> length >> k;
	vector<int> data(length);

	for(int i = 0; i < length; i++) {
		cin >> data[i];
	}

	SlidingRangeMaximumQuery(data, length, k);

	return 0;
}
