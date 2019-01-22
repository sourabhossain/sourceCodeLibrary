/**
 *  Name: Divisors
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>
#define SIZE 1000002

using namespace std;

vector<int> divisors[SIZE];

void Divisors() {
	for(int i = 1; i < SIZE; i++) {
		for(int j = i; j < SIZE; j += i) {
			divisors[j].push_back(i);
		}
	}
}  

int main()
{
	Divisors();  
    int n;

    scanf("%d", &n); 

	for(int i = 1; i <= n; i++) {
		int length = divisors[i].size();
        printf("%d = ", i);

		for(int j = 0; j < length; j++) {
			printf("%d ", divisors[i][j]);
		}
		putchar('\n');
	}

	return 0;
}