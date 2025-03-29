/**
 *  Name: Direction of a Line Segment
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

pair<double, double> subtract(pair<double, double> a, pair<double, double> b) {
	pair<double, double> result;

	result.first = a.first - b.first;
	result.second = a.second - b.second;

	return result;
}  

int getDirection(pair<double, double> a, pair<double, double> b, pair<double, double> p) {
	b = subtract(b, a);  
	p = subtract(p, a); 

	double crossProduct = (b.first * p.second) - (b.second * p.first);

	if(crossProduct > 0.0) {
		return 1;
	} else if(crossProduct < 0.0) {
		return -1;
	} else {
		return 0;
	}
}  

int main()
{
	pair<double, double> a, b, p;

	cin >> a.first >> a.second >> b.first >> b.second >> p.first >> p.second;

	int direction = getDirection(a, b, p);

	if(direction > 0) {
		puts("Left");
	} else if(direction < 0) {
		puts("Right");
	} else {
		puts("On The Line");
	}

	return 0;
}