// Given N workers standing on a road of infinite length and two arrays point[] and time[] each of size N, such that point[i] is point where the ith worker is standing and time[i] is time needed for the ith worker to finish his task, find the minimum time when all the workers can finish their tasks and meet at a point. Consider that all the workers move with the same speed (1 unit distance per unit time). The worker has to finish the task before starting to move.

// Note: The answer should be correct up to 6 decimal places.


#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Method to calculate the minimum time needed for all
// workers to reach point X
double solve(ll* point, ll* time, ll N, double X)
{
	double maxTime = 0;
	for (int i = 0; i < N; i++) {
		maxTime = max(maxTime, abs(point[i] - X) + time[i]);
	}
	return maxTime;
}

int main()
{
	ll N = 3;
	ll point[] = { 1, 2, 3 };
	ll time[] = { 2, 2, 3 };
	// Initialize the range of meeting point
	double lo = *min_element(point, point + N),
		hi = *max_element(point, point + N);

	// Reduce the range by 200 iterations
	ll cnt = 200;

	// Ternary Search
	while (cnt--) {
		double mid1 = lo + (hi - lo) / 3.0;
		double mid2 = hi - (hi - lo) / 3.0;
		double val1 = solve(point, time, N, mid1);
		double val2 = solve(point, time, N, mid2);
		if (val1 == val2) {
			lo = mid1;
			hi = mid2;
		}
		else if (val1 < val2) {
			hi = mid2;
		}
		else {
			lo = mid1;
		}
	}
	cout << fixed << setprecision(6)
		<< solve(point, time, N, lo) << "\n";
}
