/** 
 * Name: Print All Subarrays with Zero Sum
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> findSubArrays(int data[], int n) {
	unordered_map<int, vector<int>> m;
	vector<pair<int, int>> result;
	int sum = 0;

	for(int i = 0; i < n; i++) {
		sum += data[i];

		if(sum == 0) {
			result.push_back(make_pair(0, i));
        }

		if(m.find(sum) != m.end()) {
			vector<int> v = m[sum];

			for(auto item : v) {
				result.push_back(make_pair(item + 1, i));
            }
		}

		m[sum].push_back(i);
	}

	return result;
}

void print(vector<pair<int, int>> data) {
	for(auto item : data) {
		cout << "Subarray found from Index " << item.first << " to " << item.second << endl;
    }
}

int main()
{
    int n;

    scanf("%d", &n);
	int data[n];

	for(int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
	}

	vector<pair<int, int>> result = findSubArrays(data, n);

    if(result.size() == 0) {
		cout << "No subarray exists" << endl;
    } else {
		print(result);
    }

	return 0;
}
