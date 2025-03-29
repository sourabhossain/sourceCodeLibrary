/**
 *  Name: Convex Hull
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>
#define MAX 100009
#define square(x) (x * x)

using namespace std;

struct point {
	long long x, y;
} P[MAX], C[MAX], PO;

inline long long triangleArea(point a, point b, point c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}  

inline long long distancePoint(point a, point b) {
	return square(a.x - b.x) + square(a.y - b.y);
} 

bool comp(point a, point b) {
	if(triangleArea(PO, a, b) == 0) {
		return distancePoint(PO, a) < distancePoint(PO, b);
	}

	double d1x = a.x - PO.x;
	double d1y = a.y - PO.y;
	double d2x = b.x - PO.x;
	double d2y = b.y - PO.y;

	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; 
}

void convexHull(int np, int &nc) {
	int position = 0;

	for(int i = 1; i < np; i++) {
		if(P[i].x < P[position].x || (P[i].x == P[position].x && P[i].y > P[position].y)) {
			position = i;
		}
	}

	swap(P[0], P[position]);
	PO = P[0];

	sort(&P[1], P + np, comp);
	C[0] = P[0]; 
	C[1] = P[1]; 
	C[2] = P[2];

	int j = 3;

	for(int i = 3; i < np; i++) {
		while(triangleArea(C[j - 2], C[j - 1], P[i]) <= 0) {
			j--;
		}

		C[j++] = P[i];
	}

	nc = j; 
}

int main(int argc, char const *argv[])
{
	int np, nc;
	
	scanf("%d", &np);

	for(int i = 0; i < np; i++) {
		scanf("%lld%lld", &P[i].x, &P[i].y);
	}

	convexHull(np, nc);

	for(int i = 0; i < nc; i++) {
		printf("%lld %lld\n", C[i].x, C[i].y);
	}

	return 0;
}