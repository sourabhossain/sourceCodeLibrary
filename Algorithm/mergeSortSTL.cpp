/**
 *  Name: Merge Sort STL
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

template<typename Type>
void mergeSort(Type left, Type right) {
    int n = right - left;

    if(n < 2) {
        return;
    }

    int mid = n >> 1;
    mergeSort(left, left + mid);
    mergeSort(left + mid, right);

    typename remove_reference<decltype(*left)>::type* sth = new typename remove_reference<decltype(*left)>::type[n];

    for(int i = 0; i < n; i++) {
        sth[i] = *(left + i);
    }

    merge(sth, sth + mid, sth + mid, sth + n, left);
    delete[] sth;
}

int main()
{
    vector<int> data = {7, 4, 6, 2, 5};

    mergeSort(data.begin(), data.end());

    for(int item : data) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
