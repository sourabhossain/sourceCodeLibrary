/**
 *	Name: N Number LCM
 *	Author Name: Sourav Hossain
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

int n_lcm(int *data, int size) {
	int LCM = data[0];

	for(int i = 1; i < size; i++) {
		LCM = (LCM / gcd(LCM, data[i])) * data[i];
	}

	return LCM;
}  

int main()
{
	int size;
    
	scanf("%d", &size);
	int *data = new int(size);
    
    for(int i = 0; i < size; i++) {
    	scanf("%d", &data[i]);
    }

    printf("%d\n", n_lcm(data, size));

    delete [] data;
	return 0;
}