/**
  * Name: Power    
  * Author Name: Sourav Hossain
  */

#include <bits/stdc++.h>

using namespace std;

int power(int b, int p) {
    int result = 1;
    
    while(p) {
        if(p & 1) {
            result *= b;
        }

        p >>= 1;
        b *= b;
    }

    return result;
}

int main()
{
	int b, p;

	scanf("%d%d", &b, &p);
	printf("%d\n", power(b, p));

	return 0;
}