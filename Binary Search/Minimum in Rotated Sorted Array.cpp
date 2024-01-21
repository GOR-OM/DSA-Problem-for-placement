#include <bits/stdc++.h>
using namespace std;

int findMin(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    int mid;
    int ans = INT_MAX;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[low] <= arr[high])
        {
            ans = min(ans, arr[low]);
            break;
        }
        // left side is sorted
        if (arr[low] <= arr[mid] && arr[mid] >= arr[high])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else
        {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

// Other method :)

int solve(int l, int r, vector<int> &nums)
{
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] < nums[r])
        {
            r = mid;
        }
        else
            l = mid + 1;
    }
    return l;
}
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        int n = solve(l, r, nums);
        return nums[n];
    }
};