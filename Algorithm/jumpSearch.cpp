/**
 * Name: Jump Search
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

bool jumpSearch(vector<int>& data, int key) {
    int length = data.size(), root = sqrt(length);
    int previous = 0, step = root;

    while(step < length && data[step] < key) {
		previous = step;
		step += root;

		if(previous >= length) {
			return false;
		}
	}

	int minStep =  min(step, length);

    while(data[previous] < key) {
		previous++;

		if(previous == minStep) {
			return false;
		}
	}

	if(data[previous] == key) {
		return true;
	}

	return false;
}

int main()
{
	int length, key;

	scanf("%d%d", &length, &key);
	vector<int> data(length);

	for(int i = 0; i < length; i++) {
		scanf("%d", &data[i]);
	}
     
	if(jumpSearch(data, key)) {
		puts("Yes");
	} else {
		puts("No");
	}

	return 0;
}
