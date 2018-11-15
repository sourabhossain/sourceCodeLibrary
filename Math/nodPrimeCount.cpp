/**
 * Name: N-Number NOD Prime Number
 * Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>
 
using namespace std;

void nodPrime(int n) {
    map <int, int> count;
    
    while((n & 1) == 0) {
        count[2]++;
        n >>= 1;
    }
    
    int root = sqrt(n);
    
    for(int i = 3; i <= root; i += 2) {
        while(n % i == 0) {
            count[i]++;
            n /= i;
        }
    }
    
    if(n > 1) {
        count[n]++;
    }
    
    for(map <int, int>::iterator it = count.begin(); it != count.end(); ) {
        printf("%d^%d", it->first, it->second);
        
        if(++it != count.end()) {
            printf(" + ");
        }
    }
    putchar('\n');
}

int main()
{
    int n;
    
    scanf("%d", &n);
    nodPrime(n);
    
    return 0;
}