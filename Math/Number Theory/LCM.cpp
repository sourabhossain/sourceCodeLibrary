/**
 * Name: LCM
 * Author Name: Sourab Hossain
 */

#include <stdio.h>

int gcd(int first, int second) {

    while(second) {
        second ^= first ^= second ^= first %= second;
    }

    return first;
}  

int lcm(int first, int second) {
    return (first / gcd(first, second)) * second;
}

int main()
{
    int first, second;

    scanf("%d%d", &first, &second);
    printf("%d\n", lcm(first, second));
    
    return 0;
}