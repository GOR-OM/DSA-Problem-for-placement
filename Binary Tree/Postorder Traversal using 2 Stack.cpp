#include <iostream>
#include <vector>
#include <stack>
using namespace std;
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
    if (root == NULL) {
        return result;
    }

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* current = s1.top();
        s1.pop();
        s2.push(current);

        if (current->left) {
            s1.push(current->left);
        }

        if (current->right) {
            s1.push(current->right);
        }
    }

    // Populate the result vector
    while (!s2.empty()) {
        Node* current = s2.top();
        result.push_back(current->data);
        s2.pop();
    }

    return result;
}