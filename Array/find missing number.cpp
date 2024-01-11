#include <bits/stdc++.h>
using namespace std;

int findMissingNumber(const std::vector<int>& nums, int n) {
    // XOR all numbers from 1 to n
    int xor1 = 1;
    for (int i = 2; i <= n; ++i) {
        xor1 ^= i;
    }

    // XOR all elements in the array
    int xor2 = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        xor2 ^= nums[i];
    }

    // The result is the missing number
    return xor1 ^ xor2;
}

// we can also use the above function to find the missing number and other methods is sum all the numbers from 1 to n and subtract the sum of the array



// int findMissingNumber(const std::vector<int>& nums) {
//     int n = nums.size();
//     int sum = 0;
//     for (int i = 0; i < n; ++i) {
//         sum += i + 1;
//     }
//     return sum - std::accumulate(nums.begin(), nums.end(), 0);
// }

