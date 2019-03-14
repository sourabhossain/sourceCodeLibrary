/**
 *  Name: Map Value Sort
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

template<typename key, typename value>
multimap<value, key> valueSort(map<key, value> const &m) {
	multimap<value, key> mm;

	for(auto const &item : m) {
		mm.insert({item.second, item.first});
	}

	return mm;
}

int main(int argc, char const *argv[])
{
	map<string, int> m = {{"two", 2}, {"one", 1}, {"five", 5}, {"four", 4}, {"three", 3}};
	multimap<int, string> mm = valueSort(m);

	for(auto const &item : mm) {
		cout << item.second << " " << item.first << endl;
	}

	return 0;
}
