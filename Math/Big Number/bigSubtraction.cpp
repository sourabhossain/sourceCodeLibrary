/**
 *  Name: Big Number Subtraction
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

bool isSmaller(string first, string second) {
	int firstLength = first.size(), secondLength = second.size();

	if(firstLength < secondLength) {
		return true;
	}

	if(firstLength > secondLength) {
		return false;
	}

	for(int i = 0; i < firstLength; i++) {
		if(first[i] < second[i]) {
			return true;
		} else if(first[i] > second[i]) {
			return false;
		}
	}

    return false;
}

string bigSubtraction(string first, string second) {
	if(isSmaller(first, second)) {
		swap(first, second);
	}

	string result = "";
	int firstLength = first.size(), secondLength = second.size();
	int difference = firstLength - secondLength, carry = 0;

	for(int i = secondLength - 1; i >= 0; i--) {
		int sub = (first[i + difference] - '0') - (second[i] - '0') - carry;

		if(sub < 0) {
			sub += 10;
			carry = 1;
		} else {
			carry = 0;
		}

		result += (sub + '0');
	} 

	for(int i = difference - 1; i >= 0; i--) {
		if(first[i] == '0' && carry) {
			result += '9';
			continue; 
		}

		int sub = (first[i] - '0') - carry;

		if(i || sub) {
			result += (sub + '0');
		}

		carry = 0;
	}

	while(result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	string first, second;

	cin >> first >> second;
	cout << bigSubtraction(first, second) << endl;
    
	return 0;
}