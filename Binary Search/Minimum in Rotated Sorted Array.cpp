# include <bits/stdc++.h>
using namespace std ;

int findMin(int arr[], int n){
    int low = 0;
    int high = n-1;
    int mid;
    int ans = INT_MAX;
    while(low<=high){
        mid= low + (high-low)/2 ;
        if (arr[low] <= arr[high]) {
            ans = min(ans, arr[low]);
            break;
        }
        // left side is sorted 
        if(arr[low]<= arr[mid] && arr[mid]>= arr[high]){
            ans = min(ans,arr[low]);
            low = mid+1;
        }
        else {
            ans = min(ans,arr[mid]);
            high = mid-1;
        }

    }
    return ans;
}