#include <stack>
#include <iostream>

using namespace std;

template <class T>
struct Node{
    T data;
    Node* left, right;
};

void inOrderRecursive (Node<int>* curr) {
    if (curr == NULL) return;

    inOrderRecursive(curr->left);
    cout << curr->data << " ";
    inOrderRecursive(curr->right);
}

void postOrderIterative (Node<int>* root) {
    stack<Node<int>*> stk;
    stack<int> orderedStk;
    stk.push(root);

    while (!stk.empty()) {
        Node<int>* curr = stk.top();
        orderedStk.push(curr->data);
        stk.pop();
        
        if (curr->left != NULL) {
            stk.push(curr->left);
        }
        if (curr->right != NULL) {
            stk.push(curr->right);
        }
    }

    while (!orderedStk.empty()) {
        cout << orderedStk.top() << " ";
        orderedStk.pop();
    }
}

void inOrderIterative (Node<int>* root) {
    stack<Node<int>*> stk;
    Node<int>* curr = root;

    while (curr != NULL || !stk.empty()) {
        if (curr != NULL) {
            stk.push(curr);
            curr = curr->left;
        } else {
            curr = stk.top();
            stk.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}

void preOrderIterative (Node<int>* root) {
    stack<Node<int>*> stk;
    stk.push(root);

    while (!stk.empty()) {
        Node<int>* curr = stk.top();
        stk.pop();
        cout << curr->data << " ";

        if (curr->right != NULL) 
        {
            stk.push(curr->right);
        }
        if (curr->left != NULL) 
        {
            stk.push(curr->left);
        }
    }
    
}