#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;

struct Node {
    char data;
    int freq;
    Node *left, *right;
    Node(char d, int f) {
        data = d;
        freq = f;
        left = right = nullptr;
    }
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void printCodes(Node* root, string str) {
    if (!root) return;
    if (root->data != '$') {
        cout << root->data << ": " << str << "\n";
    }
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for (int i = 0; i < n; i++) {
        char ch;
        int freq;
        cin >> ch >> freq;
        minHeap.push(new Node(ch, freq));
    }

    while (minHeap.size() != 1) {
        Node *left = minHeap.top(); minHeap.pop();
        Node *right = minHeap.top(); minHeap.pop();
        
        Node *top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        
        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");

    return 0;
}
