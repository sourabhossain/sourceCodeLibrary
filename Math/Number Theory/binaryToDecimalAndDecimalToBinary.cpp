/**
  *  Name: Binary to Decimal and Decimal to Binary 
  *  Author Name: Sourab Hossain
  */
#include <bits/stdc++.h>

using namespace std;

string decimal_to_binary(long long n) {
    string binary = "";
    
    while (n) {
        binary = ((n & 1) ? "1" : "0") + binary;
        n >>= 1;
    }

    return binary;
}

long long binary_to_decimal(string number) {
    long long decimal = 0, length = number.size(), base = 0;

    while (--length >= 0) {
        decimal += (number[length] - '0') << base++;
    }

    return decimal;
}

int main(int argc, char const *argv[])
{
    long long number = 11;

    cout << decimal_to_binary(number) << endl;
    cout << binary_to_decimal("1011") << endl;

    return 0;
}
