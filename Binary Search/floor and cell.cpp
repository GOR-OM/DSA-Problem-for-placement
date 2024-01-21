// floor and cell in sorted array

// Floor : largest in array <= m
// Cell : smallest in array >= m  (lower_bound)

#include <bits/stdc++.h>
using namespace std;

int floor(vector<int>& arr, int m)
{
    int low = 0, n = arr.size();
    int high = n - 1;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= m) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int cell (vector<int>& arr, int m)
{
    int low = 0, n = arr.size();
    int high = n - 1;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= m) {
            ans = mid;
            high= mid - 1;
        } else {
            low = mid+1;
        }
    }
    return ans;
}