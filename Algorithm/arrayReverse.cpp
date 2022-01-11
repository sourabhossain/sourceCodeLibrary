/**
 * Name: Array Reverse
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

void arrayReverse(int *data, int n) {
    int first = 0, last = n - 1;

    while(first < last) {
        swap(data[first], data[last]);
        first++;
        last--;
    }
}

void arrayReverse2(int *data, int n) {
    int *first = data, *last = data + n - 1;

    while(first < last) {
        swap(*first, *last);
        first++;
        last--;
    }
}

template <typename Type> void arrayReverse3(Type *first, Type *last) {
    if(first != last) {
        while(true) {
            swap(*first, *last);
            first++;

            if(first == last) {
                break;
            }

            last--;

            if(first == last) {
                break;
            }
        }
    }
}

int main()
{
    int data[] = {10, 20, 30, 40, 50};
    int n = sizeof(data) / sizeof(data[0]);

    arrayReverse(data, n);
    // arrayReverse2(data, n);
    // arrayReverse3(data, data + n - 1);

    for(int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
