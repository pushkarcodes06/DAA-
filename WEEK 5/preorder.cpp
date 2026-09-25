#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* buildTree() {
    int rootVal;
    cout << "Enter root value (-1 for empty): ";
    cin >> rootVal;
    if (rootVal == -1) return nullptr;

    Node* root = new Node(rootVal);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        int leftVal, rightVal;

        cout << "Enter left child of " << curr->val << " (-1 if none): ";
        cin >> leftVal;
        if (leftVal != -1) {
            curr->left = new Node(leftVal);
            q.push(curr->left);
        }

        cout << "Enter right child of " << curr->val << " (-1 if none): ";
        cin >> rightVal;
        if (rightVal != -1) {
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }
    }
    return root;
}

void preorder(Node* r) { 
    if (!r) return; 
    cout << r->val << " "; 
    preorder(r->left);  
    preorder(r->right); 
}

int main() {
    Node* root = buildTree();
    cout << "\nPreorder Traversal: "; 
    preorder(root);
    cout << endl;
    return 0;
}
