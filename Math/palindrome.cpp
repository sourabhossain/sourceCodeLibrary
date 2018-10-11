/**
 * Name: Number Palindrome
 * Author Name: Sourav Hossain
 */

#include <stdio.h>

int reverseNumber(int number) {
	int reverse = 0;

	while(number) {
		reverse = reverse * 10 + (number % 10);
		number /= 10;
	}
     
	return reverse;
} 

bool palindrome(int number) {
	if(reverseNumber(number) == number) {
		return true;
	}

	return false;
}  

int main()
{
	int number;

	scanf("%d", &number);

	if(palindrome(number)) {
		puts("Yes");
	} else {
		puts("No");
	}

	return 0;
}