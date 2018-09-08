/**
 * Name: Linear Search
 * Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

bool linearSearch(vector <int> data, int key) {
    int length = data.size();

	for(int i = 0; i < length; i++) {
		if(data[i] == key) {
			return true;
		}
	}

	return false;
} // end linearSearch

int main()
{
	int length, keyValue;

    scanf("%d%d", &length, &keyValue);
    vector <int> data(length);

    for(int i = 0; i < length; i++) {
        scanf("%d", &data[i]);
    }

    if(linearSearch(data, keyValue)) {
        puts("Yes");
    } else {
        puts("No");
    }

	return 0;
}