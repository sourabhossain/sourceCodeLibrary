#include <bits/stdc++.h>

using namespace std;

class TimeMap {
    unordered_map<string, map<int, string>> hm;

    public:
        TimeMap() {}

        void set(string key, string value, int timestamp) {
            hm[key].insert({timestamp, value});
        }

        string get(string key, int timestamp) {
            auto it = hm[key].upper_bound(timestamp);
            return (it == hm[key].begin())? "" : prev(it)->second;
        }
};

int main()
{
    TimeMap object;

    object.set("key", "vlaue 01", 101);
    object.set("key", "vlaue 02", 102);
    object.set("key", "vlaue 03", 103);
    object.set("key", "vlaue 04", 104);

    cout << object.get("key", 104) << endl;

    return 0;
}
