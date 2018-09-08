/**
  *  Name: NOD
  *  Author Name: Sourav Hossain
  */

#include <bits/stdc++.h>

using namespace std;

int main() 
{
	int n;

	scanf("%d", &n);
    
    set<int> nod;
	int root = sqrt(n);
    
    nod.insert(1);
    nod.insert(n);

    for(int i = 2; i <= root; i++) {
    	if(n % i == 0) {
    		nod.insert(i);
    		nod.insert(n / i);
    	}
    }
    
    printf("%d = ", n); 
    for(set<int>::iterator it = nod.begin(); it != nod.end(); it++) {
    	printf("%d ", *it);
    }
    putchar('\n');

	return 0;
}