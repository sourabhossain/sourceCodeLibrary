/**
 *  Name: All Sub Set Sum
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int allSubSetSum(vector<int>& v, int n) {
    int sum = 0;

    for(int i = 0; i < n; i++) {
    	sum += v[i];
    }	

    return sum * (1 << (n - 1));
}

int main()
{
	int n;

	cin >> n;
	vector<int> v(n);

	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}

	cout << allSubSetSum(v, n) << endl;

	return 0;
}