/**
 * Name: Number To Roman Number
 * Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

string numberToRomanNumber(int number) {
    string roman = "";

    while(number > 0) {
        if(number >= 1000) {
            roman += "M";
            number -= 1000;
        } else if(number >= 900) {
            roman += "CM";
            number -= 900;
        } else if(number >= 500) {
            roman += "D";
            number -= 500;
        } else if(number >= 400) {
            roman += "CD";
            number -= 400;
        } else if(number >= 100) {
            roman += "C";
            number -= 100;
        } else if(number >= 90) {
            roman += "XC";
            number -= 90;
        } else if(number >= 50) {
            roman += "L";
            number -= 50;
        } else if(number >= 40) {
            roman += "XL";
            number -= 40;
        } else if(number >= 10) {
            roman += "X";
            number -= 10;
        } else if(number >= 9) {
            roman += "IX";
            number -= 9;
        } else if(number >= 5) {
            roman += "V";
            number -= 5;
        } else if(number >= 4) {
            roman += "IV";
            number -= 4;
        } else {
            roman += "I";
            number -= 1;
        }
    }

    return roman;
} // end numberToRomanNumber function

int main()
{
    int number;
    
    printf("Input: ");
    scanf("%d", &number);
    printf("Output: %s\n", numberToRomanNumber(number).c_str());

    return 0;
}
