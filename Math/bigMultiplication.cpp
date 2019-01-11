/**
 *  Name: Big Number Multiplication
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

string bigMultiplication(string first, string second) {
	int firstLength = first.size(), secondLength = second.size();

	if(firstLength == 0 || secondLength == 0) {
		return "0";
	}

	vector<int> result(firstLength + secondLength, 0);
	int k = 0;

	for(int i = firstLength - 1; i >= 0; i--) {
		int carry = 0, l = 0;

		for(int j = secondLength - 1; j >= 0; j--) {
			carry += (first[i] - '0') * (second[j] - '0') + result[k + l];
            result[k + l] = carry % 10;
			carry /= 10;
			l++;
		}

		if(carry) {
			result[k + l] += carry;
		}

		k++;
	}

	int i = result.size() - 1;
	while(i > 0 && result[i] == 0) {
		i--;
	}

	string ans = "";
	while(i >= 0) {
		ans += result[i--] + '0';
	}

	return ans;
}

int main()
{
    string first, second;

    cin >> first >> second;
    cout << bigMultiplication(first, second) << endl;

	return 0;
}