/**
 * Name: String Reverse
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

void stringReverse(string& line) {
    int length = line.size();

    for(int i = 0; i < length; i++) {
        swap(line[i], line[--length]);
    }
}

int main()
{
    string line;

    getline(cin, line);
    stringReverse(line);
    cout << line << endl;

    return 0;
}
