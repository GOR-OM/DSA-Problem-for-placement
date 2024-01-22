// Problem statement
// You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. The packages must be shipped within 'd' days.

// The weights of the packages are given in an array 'weights'. The packages are loaded on the conveyor belts every day in the same order as they appear in the array. The loaded weights must not exceed the maximum weight capacity of the ship.

// Find out the least-weight capacity so that you can ship all the packages within 'd' days.

#include <bits/stdc++.h>
using namespace std;

int find_capacity(vector<int> &weights, int days, int capacity)

{

    int n = weights.size(), ans = 1, sum = 0;

    for (int i = 0; i < n; i++)

    {

        if ((weights[i] + sum) > capacity)

        {

            ans++;

            sum = weights[i];
        }

        else

        {

            sum += weights[i];
        }
    }

    return ans;
}

int leastWeightCapacity(vector<int> &weights, int days)

{

    int n = weights.size();

    int start = *max_element(weights.begin(), weights.end()), mid;

    int end = accumulate(weights.begin(), weights.end(), 0);

    while (start <= end)

    {

        mid = start + (end - start) / 2;

        int ans = find_capacity(weights, days, mid);

        if (ans <= days)

        {

            end = mid - 1;
        }

        else

        {

            start = mid + 1;
        }
    }

    return start;
}