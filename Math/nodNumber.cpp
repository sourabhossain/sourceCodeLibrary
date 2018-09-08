/**
 * Name: N-Number NOD Number
 * Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>
#define SIZE 10001

using namespace std;

vector <int> smallestFactor(SIZE);

void smallestFactorGenerator() {
    for(int i = 2; i < SIZE; i += 2) {
        smallestFactor[i] = 2;
    }

    for(int i = 3; i < SIZE; i += 2) {
        if(!smallestFactor[i]) {
            smallestFactor[i] = i;

            for(int j = i * i; j < SIZE; j += i << 1) {
                if(!smallestFactor[j]) {
                    smallestFactor[j] = i;
                }
            }
        }
    }
} // end smallestFactorGenerator function

void nodNumber(int n) {
    map <int, int> nod;

    while(n > 1) {
        nod[smallestFactor[n]]++;
        n /= smallestFactor[n]; 
    }

    for(map <int, int>::iterator it = nod.begin(); it != nod.end();) {
        printf("%d^%d", it->first, it->second);

        if(++it != nod.end()) {
            printf(" + ");
        }
    }
    putchar('\n');
} // end nodNumber function

int main()
{
    int n;
    smallestFactorGenerator(); // go to smallestFactorGenerator function

    while(scanf("%d", &n) != EOF) {
        printf("%d = ", n);
        nodNumber(n); // go to nodNumber function
    }

    return 0;
}
