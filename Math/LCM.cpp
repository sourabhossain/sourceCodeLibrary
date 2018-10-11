/**
 * Name: LCM
 * Author Name: Sourav Hossain
 */

#include <stdio.h>

int gcd(int first, int second) {
    while(second != 0) {
        int temp = second;
        second = first % second;
        first = temp;
    }

    return first;
}  

int main()
{
    int first, second;

    scanf("%d%d", &first, &second);
    printf("%d\n", (first / gcd(first, second)) * second);
    
    return 0;
}