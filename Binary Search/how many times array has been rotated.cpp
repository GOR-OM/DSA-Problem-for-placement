#include <bits/stdc++.h>
using namespace std;

int findKRotation(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    int mid;
    int mini = INT_MAX;
    int ans = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[low] <= arr[high])
        {
            if (mini >= arr[low])
            {
                mini = arr[low];
                ans = low;
            }
            break;
        }
        // left side is sorted
        if (arr[low] <= arr[mid] && arr[mid] >= arr[high])
        {
            if (arr[low] <= mini)
            {
                mini = arr[low];
                ans = low;
            }
            low = mid + 1;
        }
        else
        {
            if (arr[mid] <= mini)
            {
                mini = arr[mid];
                ans = mid;
            }
            high = mid - 1;
        }
    }
    return ans;
}
