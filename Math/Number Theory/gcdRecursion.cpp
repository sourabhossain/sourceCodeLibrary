/**
 *  Name: GCD Recursion
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int gcd(int firstElement, int secondElement) {
	return (secondElement == 0)? firstElement : gcd(secondElement, firstElement % secondElement);  
}

int main()
{
	int firstElement, secondElement;

    scanf("%d%d", &firstElement, &secondElement);
    printf("%d\n", gcd(firstElement, secondElement));

	return 0;
}