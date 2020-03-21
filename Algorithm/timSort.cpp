/**
 * Name: Tim Sort
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>
#define RUN 32

using namespace std;

void insertionSort(int *data, int left, int right) {
    for(int i = left + 1; i <= right; i++) {
        int temp = data[i];
        int j = i - 1;

        while(data[j] > temp && j >= left) {
            data[j + 1] = data[j];
            j--;
        }

        data[j + 1] = temp;
    }
}

void merge(int *data, int left, int mid, int right) {
	list<int> temp;
	int firstIndex = left, secondIndex = mid + 1;

	while(firstIndex <= mid && secondIndex <= right) {
		if(data[firstIndex] < data[secondIndex]) {
			temp.push_back(data[firstIndex++]);
		} else {
			temp.push_back(data[secondIndex++]);
		}
	}

	while(firstIndex <= mid) {
		temp.push_back(data[firstIndex++]);
	}

	while(secondIndex <= right) {
		temp.push_back(data[secondIndex++]);
	}

	for(int i = left; i <= right; i++) {
		data[i] = temp.front();
		temp.pop_front();
	}
}

void timSort(int *data, int n) {
    for(int i = 0; i < n; i += RUN) {
        insertionSort(data, i, min((i + 31), (n - 1)));
    }

    for(int i = RUN; i < n; i *= 2) {
        for(int j = 0; j < n; j += (i << 1)) {
            merge(data, j, i + j - 1, min(j + 2*i - 1, n - 1));
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

    timSort(data, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    putchar('\n');

    return 0;
}
