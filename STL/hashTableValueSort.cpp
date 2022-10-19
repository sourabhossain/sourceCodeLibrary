#include <bits/stdc++.h>

using namespace std;

struct Compare {
    bool operator()(auto& left, auto& right) const {
        if(left.first != right.first) {
            return left.first < right.first;
        }

        return left.second > right.second;
    }
};

auto valueSort(auto counter) {
    priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> q;

    for(auto it : counter) {
        q.emplace(it.second, it.first);
    }

    return q;
}

int main()
{
    map<string, int> m = {
        {"two", 2},
        {"one", 1},
        {"five", 5},
        {"four", 4},
        {"three", 3}
    };
	auto q = valueSort(m);

	while(!q.empty()) {
        cout << q.top().first << " " << q.top().second << endl;
        q.pop();
    }

    return 0;
}
