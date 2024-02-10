#include<bits/stdc++.h>
using namespace std ; 


// Function to insert an element at the correct position in a sorted stack
void insertAtCorrectPosition(stack<int> &sortedStack, int element) {
    // Base case: if the stack is empty or the element is greater than the top
    if (sortedStack.empty() || element > sortedStack.top()) {
        sortedStack.push(element);
        return;
    }

    // Pop elements greater than the current element
    int topElement = sortedStack.top();
    sortedStack.pop();

    // Recursively insert the element at the correct position
    insertAtCorrectPosition(sortedStack, element);

    // Push back the popped element
    sortedStack.push(topElement);
}

// Function to sort a stack in descending order using recursion
void sortStack(stack<int> &stack) {
    // Base case: if the stack is not empty
    if (!stack.empty()) {
        // Pop the top element
        int topElement = stack.top();
        stack.pop();

        // Recursively sort the remaining stack
        sortStack(stack);

        // Insert the popped element at the correct position in the sorted stack
        insertAtCorrectPosition(stack, topElement);
    }
}