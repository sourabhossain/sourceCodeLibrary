/**
 * Name: Merge Two Sorted Array
 * Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> mergeSortedArray(vector<int> first, vector<int> second) {
    int firstLength = first.size(), secondLength = second.size();

    if(firstLength == 0) {
        return first;
    }

    if(secondLength == 0) {
        return second;
    }

    int minLength = (firstLength < secondLength)? firstLength : secondLength;
    int j = 0, k = 0;
    vector <int> merged;

    while(j < minLength && k < minLength) {
        if(first[j] < second[k]) {
            merged.push_back(first[j++]);
        } else {
            merged.push_back(second[k++]);
        }
    }

    while(j < firstLength) {
        merged.push_back(first[j++]);
    }

    while(k < secondLength) {
        merged.push_back(second[k++]);
    }

    return merged;
}

int main()
{
    vector<int> first = {4, 6, 8, 8, 10, 17, 29};
    vector<int> second = {2, 3, 5, 8, 13, 17, 31, 33};

    vector<int> merged = mergeSortedArray(first, second);
    int length = merged.size();

    for(int i = 0; i < length; i++) {
        printf("%d ", merged[i]);
    }
    putchar('\n');

    return 0;
}
