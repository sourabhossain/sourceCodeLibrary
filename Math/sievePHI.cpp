/**
 *  Name: sievePHI
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>
#define SIZE 10000001

using namespace std;

int phi[SIZE];

void sievePHI() {
    phi[1] = 1;

    for(int i = 2; i < SIZE; i++) {
        if(phi[i] == 0) {
            phi[i] = i - 1;

            for(int j = i << 1; j < SIZE; j += i) {
                if(phi[j] == 0) {
                    phi[j] = j;
                }

                phi[j] /= i;
                phi[j] *= (i - 1);
            }
        }
    }
}

int main()
{
    sievePHI();

    for(int i = 1; i < 101; i++) {
        printf("%d\t", phi[i]);
    }

    return 0;
}