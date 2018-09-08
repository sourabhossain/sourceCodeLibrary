/**
  *  Name: Nth Polygon Area 
  *  Author Name: Sourav Hossain
  */

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);
	vector<pair<double, double> > point(n);

	for(int i = 0; i < n; i++) {
		cin >> point[i].first >> point[i].second;
	}

	double area = 0.0;

	for(int i = 1; i < n; i++) {
		area += ((point[i - 1].first * point[i].second) - (point[i - 1].second * point[i].first));
	}

	cout << abs(area / 2.0) << endl;

	return 0;
}