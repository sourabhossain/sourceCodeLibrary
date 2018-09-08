/**
 * Name: String Reverse
 * Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

void stringReverse(char *string) {
    int length = strlen(string);

    for(int i = 0; i < length; i++) {
        string[i] ^= string[--length];
        string[length] ^= string[i];
        string[i] ^= string[length];
    }
} // end stringReverse function

int main()
{
    char string[1001];

    gets(string);
    stringReverse(string); // go to stringReverse function
    puts(string);

    return 0;
}
