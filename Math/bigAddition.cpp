/**
  *  Name: Big Number Addition    
  *  Author Name: Sourav Hossain 
  */

#include <bits/stdc++.h>

using namespace std;

string bigAddition(string first, string second) {
	if(first.size() > second.size()) {
		swap(first, second);
	}

	string result = "";
    int firstLength = first.size(), secondLength = second.size();
    int carry = 0, difference = secondLength - firstLength;

    for(int i = firstLength - 1; i >= 0; i--) {
    	carry += (first[i] - '0') + (second[i + difference] - '0');
    	result += (carry % 10) + '0';
    	carry /= 10;
    }

    for(int i = difference - 1; i >= 0; i--) {
    	carry += (second[i] - '0');
    	result += (carry % 10) + '0';
    	carry /= 10;
    }

    if(carry) {
    	result += (carry + '0');
    }

	reverse(result.begin(), result.end());
	return result;
} // end bigAddition function

int main()
{
	string first, second;

	cin >> first >> second;
	cout << bigAddition(first, second) << endl; // go to bigAddition function

	return 0;
}