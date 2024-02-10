#include<bits/stdc++.h>
using namespace std ;



int largestRectangle(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    vector<int> left_smaller(n, -1);
    vector<int> right_smaller(n, n);

    // Find the left smaller element for each bar
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (!st.empty()) {
            left_smaller[i] = st.top();
        }
        st.push(i);
    }

    while (!st.empty()) {
        st.pop();
    }

    // Find the right smaller element for each bar
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (!st.empty()) {
            right_smaller[i] = st.top();
        }
        st.push(i);
    }

    int maxArea = 0;

    // Calculate the area for each bar and find the maximum
    for (int i = 0; i < n; i++) {
        int width = right_smaller[i] - left_smaller[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}






int largestRectangle(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
            int height = (i == n) ? 0 : heights[i];
            int width = (st.empty()) ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
            if (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
        }
        st.push(i);
    }

    return maxArea;
}