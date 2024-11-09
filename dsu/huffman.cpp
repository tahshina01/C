#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    char data;
    int freq;
    Node *left,*right;

    Node(char data, int freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

class compare {
public:
    bool operator()(Node* l, Node* r) {
        return (l->freq > r->freq);
    }
};


void printCodes(Node* root, string str) {
    
    if (!root) {
        return;
    }
    if (root->data != '-') {
        cout << root->data << ": " << str << endl;
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}


void HuffmanCodes(char data[], int freq[], int size) {
    Node *left, *right, *tmp;

    
    priority_queue<Node*, vector<Node*>, compare> minheap;

    for (int i = 0; i < size; i++) {
        minheap.push(new Node(data[i], freq[i]));
    }

    
    while (minheap.size() != 1) {
        
        left = minheap.top();
        minheap.pop();

        right = minheap.top();
        minheap.pop();

        

        tmp = new Node('-', left->freq + right->freq);
        tmp->left = left;
        tmp->right = right;

        minheap.push(tmp);
    }

    
    printCodes(minheap.top(), " ");
}

int main() {
    char arr[] = {'a','b','c','d','e'};
    int freq[] = {10,5,2,14,15};

    int size = sizeof(arr)/sizeof(arr[0]);
    HuffmanCodes(arr,freq,size);

    return 0;
}
