/**
 * Name:Gnome Sort
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

void gnomeSort(int *data, int n) {
    int index = 0;

    while(index < n) {
        if(index == 0) {
            index++;
        }

        if(data[index] >= data[index - 1]) {
            index++;
        } else {
            swap(data[index], data[index - 1]);
            index--;
        }
    }
}

int main()
{
    int n;

    scanf("%d", &n);
    int data[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    gnomeSort(data, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    putchar('\n');

    return 0;
}
