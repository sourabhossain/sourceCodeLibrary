/**
 * Name: N Number GCD
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

int gcd(int first, int second) {
    int temp;
    
    while(second != 0) {
        temp = second;
        second = first % second;
        first = temp;
    }
    
    return first;
}  

int n_gcd(int *data, int size) {
	int i, GCD = data[0];

	for(i = 1; i < size; i++) {
		GCD = gcd(GCD, data[i]);

        if(GCD == 1) {
            return 1;
        }  
	}

	return GCD;
}  

int main()
{
    int size;

    scanf("%d", &size);
    int *data =  new int(size);
    
    for(int i = 0; i < size; i++) {
    	scanf("%d", &data[i]);
    }

    printf("%d\n", n_gcd(data, size));

    delete [] data;
	return 0;
} 