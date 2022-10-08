#include <bits/stdc++.h>

using namespace std;

string printTwosComplementRepresentation(int n) {
     string result = "";

     for(int i = 31; i >= 0; i--) {
         result += ((1 << i) & n)? "1" : "0";
     }

     return result;
}

int main()
{
    int n;

    cin >> n;
    cout << printTwosComplementRepresentation(n) << endl;

    return 0;
}
