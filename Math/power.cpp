/**
  * Name: Power    
  * Author Name: Sourav Hossain
  */

#include <bits/stdc++.h>

using namespace std;

int power(int n, int p) {
    string binary = "";

    while(p) {
    	(p & 1)? binary += "1" : binary += "0";
    	p >>= 1;
    }	
    
    int result = 1;

    for(int i = binary.size() - 1; i >= 0; i--) {
    	result *= result;

    	if(binary[i] == '1') {
    		result *= n;
    	}
    }

    return result;
} // end power function

int main()
{
	int n, p;

	scanf("%d%d", &n, &p);
	printf("%d\n", power(n, p));

	return 0;
}