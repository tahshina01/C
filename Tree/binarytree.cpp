#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    Node(int key) {
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = NULL;
    }

    void insert(int key) {
        root = insertNode(root, key);
    }

    void inorderTraversal() {
        cout<<"in-order traversal: ";
        inorder(root);
        cout<<endl;
    }
    void preorderTraversal() {
        cout<<"pre-order traversal: ";
        preorder(root);
        cout<<endl;
    }
    void postorderTraversal() {
        cout<<"post-order traversal: ";
        postorder(root);
        cout<<endl;
    }
    void Max(){
        findMax(root);
    }
    void deletenode(int n){
        deleteNode(root,n);
    }
    void print(){
        printTree(root);
    }
    bool leftSkewed(){
        return left_skewed(root);
    }
     bool rightSkewed(){
        return right_skewed(root);
    }
    bool perfect(){
        return Perfect(root);
    }
    bool full(){
        return Full(root);
    }
    bool iscomplete(){
        return complete(root);
    }
    Node* search(int d){
        return Search(root,d);
    }
    bool Balanced(){
        return balanced(root);
    }
    
private:
    Node* insertNode(Node* node, int key) {
        if (node == NULL) {
            return new Node(key);
        }
        if (key < node->key) {
            node->left = insertNode(node->left, key);
        }
        else if (key >= node->key) {
            node->right = insertNode(node->right, key);
        }
        return node;
    }

    void inorder(Node* node) {
        if (node == NULL) {
            return;
        }
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }
    void preorder(Node* node){
        if(node==NULL){
            return;
        }
        cout << node->key << " ";
        preorder(node->left);
        preorder(node->right);

    }
    void postorder(Node* node){
        if(node==NULL){
            return;
        }
        
        postorder(node->left);
        postorder(node->right);
        cout << node->key << " ";

    }
    void findMax(Node* node) {
        if (node == NULL) {
            cout << "The tree is empty." << endl;
        }
        while (node->right != NULL) {
            node = node->right;
        }
        cout<< "\nMax element "<<node->key<<endl;
    }
    Node* deleteNode(Node* root,int d){
        if(root==NULL){
            return root;
        }
        else if(root->key>d){
            root->left=deleteNode(root->left,d);
            return root;
        }
        else if(root->key<d){
            root->right=deleteNode(root->right,d);
        }
        if(root->left==NULL){
            Node* temp= root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else{
            Node* parent=root;
            Node* child=root->right;
            while(child->left!=NULL){
                parent=child;
                child=child->left;
            }
            if(parent!=root){
                parent->left=child->right;
            }
            else{
                parent->right=child->right;
            }
            root->key=child->key;
            delete child;
            return root;
        }
    }
    Node* isbalanced(Node* root){
        vector <Node*> node;
        storenodes(root, node);
        int n=node.size();
        return buildtree(node,0,n-1);

    }
    void storenodes(Node* root, vector<Node*> node){
        if(root==NULL){
            return;
        }
        storenodes(root->left,node);
        node.push_back(root);
        storenodes(root->right,node);

    }
    Node* buildtree(vector<Node*> node,int start, int end){
        if(start>end) return NULL;
        int mid=(start+end)/2;
        Node* root=node[mid];
        root->left=buildtree(node,start,mid-1);
        root->right=buildtree(node,mid+1,end);
        return root;
    }
    int getheight(Node* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(getheight(root->left),getheight(root->right));
    }
    bool balanced(Node* root){
        if(root==NULL){
            return true;
        }
        int leftheight=getheight(root->left);
        int rightheight=getheight(root->right);
        if(abs(leftheight-rightheight)>1){
            return false;
        }
        return balanced(root->left) && balanced(root->right);
    }
    bool Perfect(Node* root){
        if(root==NULL){
            return true;
        }
        int leftheight=getheight(root->left);
        int rightheight=getheight(root->right);
        if(abs(leftheight-rightheight)!=0){
            return false;
        }
        return Perfect(root->left) && Perfect(root->right);
    }
    bool Full(Node* root){
        if(root==NULL){
            return true;
        }
        if((root->left!=NULL && root->right==NULL) || (root->right!=NULL && root->left==NULL)){
            return false;
        }
        return Full(root->left) && Full(root->right);
    }
    void printTree(Node* root) {
    queue<Node*> q;
    q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node* node = q.front();
                q.pop();
                if (node == nullptr) {
                    cout << " ";
                    continue;
                }
                cout << node->key;
                if (i < n - 1) {
                    cout << " ";
                }
                q.push(node->left);
                q.push(node->right);
            }
            cout << endl;
        }
    }
    
    bool left_skewed(Node* root){
        if(root==NULL){
            return 1;
        }
        if(root->right!=NULL){
            return 0;
        }
        return left_skewed(root->left);
    }
    bool right_skewed(Node* root){
        if(root==NULL){
            return 1;
        }
        if(root->left!=NULL){
            return 0;
        }
        return right_skewed(root->right);
    }
    Node* Search(Node* root, int d){
        if(root==NULL||root->key==d){
            return root;
        }
        if(d<root->key){
            return Search(root->left, d);
        }
        else{
            return Search(root->right, d);
        }

    }
    bool complete(Node* root){
        if(root==NULL){
            return 1;
        }
        else if(getheight(root->left)<getheight(root->right)){
            return 0;
        }
        return getheight(root->left)>=getheight(root->right);
    }


};

int main() {
    BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(9);
    bst.insert(4);
    bst.insert(6);
   
    bst.inorderTraversal();
    bst.preorderTraversal();
    bst.postorderTraversal();
    cout<<bst.Balanced()<<endl;
    bst.deletenode(3);
    bst.insert(0);
    bst.inorderTraversal();
    cout<<bst.Balanced()<<endl;
    bst.Max();
    cout<<"perfect "<<bst.perfect()<<endl;
    cout<<"full "<<bst.full()<<endl;
    bst.print();
    BST b;
    b.insert(9);
    b.insert(8);
    b.insert(7);
    b.insert(6);
    b.insert(5);
    b.insert(4);
    b.insert(3);
    b.print();
    cout<<b.rightSkewed()<<endl;
    cout<<b.perfect()<<endl;
    cout<<"full "<<b.full()<<endl;
    Node* temp=b.search(7);
    cout<<temp->key<<endl;
    cout<<"complete "<<b.iscomplete()<<endl;

    return 0;
}
