#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> height(n);
        for (int i = 0; i < n; i++) cin >> height[i];
        vector<int> cost(n);
        for (int i = 0; i < n; i++) cin >> cost[i];

        int l = 0;
        int r = 10000;

        while (r - l > 2) {
            int w1 = l + (r - l) / 3;
            int w2 = r - (r - l) / 3;
            long long cost1 = 0;
            long long cost2 = 0;
            for (int i = 0; i < n; i++) {
                cost1 += abs(height[i] - w1) * cost[i];
                cost2 += abs(height[i] - w2) * cost[i];
            }
            if (cost1 < cost2) {
                r = w2 - 1;
            } else if(cost1 > cost2) {
                l = w1 +1;
            }
            else {
                l = w1 + 1;
                r = w2 - 1;
            }
        }

        // Calculate the minimum cost for the converged value of l and l + 1
        long long final_cost1 = 0;
        long long final_cost2 = 0;
       
        for (int i = 0; i < n; i++) {
            final_cost1 += abs(height[i] - l) * cost[i];
            final_cost2 += abs(height[i] - (l + 1)) * cost[i];
        }
       
        cout << min(final_cost1, final_cost2) << endl;
    }

    return 0;
}
