/**
  *  Name: Big Number Factorial
  *  Author Name: Sourav Hossain
  */

#include <bits/stdc++.h>

using namespace std;

string bigFactorial(int n) {
	int carry = 0, temp, res_size = 1, res[10000];

    res[0] = 1;

	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < res_size; j++) {
			temp = res[j] * i + carry;
			res[j] = temp % 10;
			carry = temp / 10;
		}

		while(carry) {
			res[res_size] = carry % 10;
			carry /= 10;
			res_size++;
		}
	}

	string result = "";

	while(res_size > 0) {
		result += res[--res_size] + '0';
	}

	return result;
}

int main(int argc, char const *argv[])
{
	int n;

	cin >> n;
	cout << bigFactorial(n) << endl;

	return 0;
}