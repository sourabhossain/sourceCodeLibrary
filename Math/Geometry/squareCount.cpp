/**
 *  Name: Square Count
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int m, n, total = 0;

	scanf("%d%d", &m, &n);

	if(m < n) {
		swap(m, n);
	}

	while(n > 0) {
		total += (m-- * n--);
	}

	printf("%d\n", total);

	return 0;
}