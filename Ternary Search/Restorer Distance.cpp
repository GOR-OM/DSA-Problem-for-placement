
#include <bits/stdc++.h>
using namespace std;

long long solve(const vector<long long>& arr, int N, long long A, long long R, long long M, long long x) {
    long long cost = 0;
    long long p = 0;
    long long q = 0;
    M = min(A + R, M);

    for (int i = 0; i < N; i++) {
        if (arr[i] > x) {
            q += arr[i] - x;
        } else {
            p += x - arr[i];
        }
    }
    
    if (p >= q) {
        cost = q * M + (p - q) * A;
    } else {
        cost = p * M + (q - p) * R;
    }
    return cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long A, R, M;
    cin >> N >> A >> R >> M;

    vector<long long> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long long l = 0;
    long long r = (long long)1e9;
    
    while (l < r) {
        long long m1 = l + (r - l) / 3;
        long long m2 = r - (r - l) / 3;

        long long cost1 = solve(arr, N, A, R, M, m1);
        long long cost2 = solve(arr, N, A, R, M, m2);

        if (cost1 > cost2) {
            l = m1 + 1;
        } else {
            r = m2 - 1;
        }
    }

    cout << solve(arr, N, A, R, M, l) << endl;

    return 0;
}
