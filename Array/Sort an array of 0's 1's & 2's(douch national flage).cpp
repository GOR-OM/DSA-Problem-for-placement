
#include<bits/stdc++.h>
using namespace std;

void sort012(int a[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
        switch (a[mid]) {
        case 0:
            swap(a[low++], a[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(a[mid], a[high--]);
            break;
        }
    }
}

// other method 

void sort012(int a[], int n)
{
    int one = 0, zero = 0, two = 0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            zero++;
        }
        else if(a[i]==1){
            one++;
        }
        else{
            two++;
        }
    }
    int j=0;
    for(j;j<zero;j++){
        a[j]=0;
    }
    for(j;j<zero+one;j++){
        a[j]=1;
    }
    for(j;j<zero+one+two;j++){
        a[j]=2;
    }
    
}