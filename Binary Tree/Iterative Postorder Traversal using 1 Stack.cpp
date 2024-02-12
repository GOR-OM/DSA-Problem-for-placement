#include <bits/stdc++.h>
using namespace std ;
struct Node 
{
    int data;
    Node* left;
    Node* right; 

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> postorderTraversal(Node* root) {
    vector<int> result;
    stack<Node*> s;

    if (root == NULL) {
        return result;
    }

    Node* current = root;

    while (current || !s.empty()) {
        while (current) {
            if (current->right) {
                s.push(current->right);
            }
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        // Check if the popped element has a right child and the right child is at the top of the stack
        if (!s.empty() && current->right == s.top()) {
            s.pop(); // Remove the right child from the stack
            s.push(current); // Push the current node back onto the stack
            current = current->right; // Move to the right child
        } else {
            result.push_back(current->data); // Visit the node
            current = NULL; // Reset current to NULL to avoid going into the left subtree again
        }
    }

    return result;
}