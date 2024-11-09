#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int key;
    string name;
    float cgpa; 
    Node* left;
    Node* right;
    Node(int key,string name,float cgpa) {
        this->key = key;
        this->name = name;
        this->cgpa = cgpa;
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

    void insert(int key, string name, float cgpa) {
        root = insertNode(root, key, name, cgpa);
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
    
private:
    Node* insertNode(Node* node, int key, string name, float cgpa) {
        if (node == NULL) {
            return new Node( key, name, cgpa );
        }
        if (key < node->key) {
            node->left = insertNode( node->left, key, name, cgpa );
        }
        else if (key >= node->key) {
            node->right = insertNode( node->right, key, name, cgpa );
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
                    cout << "/"; // for leafs child
                    continue;
                }
                cout << node->key;
                if (i < n - 1) {
                    cout << "_";// between left and right child
                }
                q.push(node->left);
                q.push(node->right);
            }
            cout << endl;
        }
    }
    
    /*
    recursion
    void printLevel(Node* root, int level) {
        if (root == nullptr) { // Base case: the root is null
            return;
        }
        if (level == 1) { // Base case: the current level is 1
            cout << root->key << " "; // Print the value of the node
        }
        else if (level > 1) { // Recursive case: the current level is greater than 1
            printLevel(root->left, level-1); // Recursively call the left subtree with level-1
            printLevel(root->right, level-1); // Recursively call the right subtree with level-1
        }
    }
    void printTree(Node* root) {
        int height = getheight(root); // Get the height of the tree
        for (int i = 1; i <= height; i++) { // Traverse the tree level by level
            printLevel(root, i); // Print the nodes at the current level
            cout << endl; // Move to the next line
        }
    }
    */
   

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
    bst.insert(5,"Mary",3.0);
    bst.insert(3,"karl",2.0);
    bst.insert(7,"gaby",2.90);
    bst.insert(1,"rahman",3.10);
    bst.insert(9,"promi",3.60);
    bst.insert(4,"haze",3.98);
    bst.insert(6,"lana",3.34);
   
    bst.inorderTraversal();
    bst.preorderTraversal();
    bst.postorderTraversal();
    bst.Max();
    cout<<"perfect "<<bst.perfect()<<endl;
    cout<<"full "<<bst.full()<<endl;
    bst.print();
    BST b;
    b.insert(9,"Mary",3.0);
    b.insert(8,"karl",2.0);
    b.insert(7,"gaby",2.90);
    b.insert(6,"rahman",3.10);
    b.insert(5,"promi",3.60);
    b.insert(4,"haze",3.98);
    b.insert(3,"lana",3.34);
    b.print();
    cout<<b.rightSkewed()<<endl;
    cout<<b.perfect()<<endl;
    cout<<"full "<<b.full()<<endl;
    Node* temp=b.search(7);
    cout<<temp->name<<endl;
    cout<<"complete "<<b.iscomplete()<<endl;

    return 0;
}
