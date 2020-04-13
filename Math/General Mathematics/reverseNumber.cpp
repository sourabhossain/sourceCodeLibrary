/**
 * Name: Reverse Number
 * Author Name: Sourab Hossain
 */

#include <stdio.h>

int reverseNumber(int data) {
    int reverse = 0;

    while(data) {
        reverse = reverse * 10 + (data % 10);
        data /= 10;
    }

    return reverse;
}  

int main() {
    
    int data;
    
    scanf("%d", &data);
    printf("%d\n", reverseNumber(data));  

    return 0;
}