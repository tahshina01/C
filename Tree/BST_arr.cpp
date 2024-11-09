#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BST{
    private:
        T* arr;
        int size;
    public:
        BST(){
            arr = NULL;
            size = 0;
        }
        void insert(T key){
            if(arr == NULL){
                arr = new T[1];
                arr[0] = key;
                size++;
            }
            else{
                T* temp = new T[size+1];
                int i=0;
                while(i<size && arr[i]<key){
                    temp[i] = arr[i];
                    i++;
                }
                temp[i] = key;
                while(i<size){
                    temp[i+1] = arr[i];
                    i++;
                }
                delete[] arr;
                arr = temp;
                size++;
            }
        }
        
        void inorderTraversal(){
            cout<<"In-order traversal: ";
            inorder(0);
            cout<<endl;
        }
        void preorderTraversal(){
            cout<<"Pre-order traversal: ";
            preorder(0);
            cout<<endl;
        }
        void postorderTraversal(){
            cout<<"Post-order traversal: ";
            postorder(0);
            cout<<endl;
        }
        void Max(){
            if(size == 0){
                cout<<"The tree is empty."<<endl;
            }
            else{
                cout<<"Max element "<<arr[size-1]<<endl;
            }
        }
        void deletenode(T n){
            int i = search(n);
            if(i == -1){
                cout<<"Element not found"<<endl;
            }
            else{
                T* temp = new T[size-1];
                int j=0;
                for(int k=0; k<size; k++){
                    if(k!=i){
                        temp[j++] = arr[k];
                    }
                }
                delete[] arr;
                arr = temp;
                size--;
            }
        }
        void print(){
            cout<<"Tree: ";
            for(int i=0; i<size; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        bool leftSkewed(){
            return left_skewed(0);
        }
         bool rightSkewed(){
             return right_skewed(0);
         }

        int getheight(int x){
        if(x>=size || arr[x]==-1){
            return 0;
        }
        return 1+max(getheight(2*x+1),getheight(2*x+2));
        }
        bool perfect(){
             return Perfect(0);
        }
        bool full(){
            return Full(0);
        }
         bool balanced(){
             return Balanced(0);
         }
        int search(T d){
            for(int i=0; i<size; i++){
                if(arr[i]==d){
                    return i;
                }
            }
            return -1;
        }

    private:
        void inorder(int i){
            if(i<size){
                inorder(2*i+1);
                cout<<arr[i]<<" ";
                inorder(2*i+2);
            }
        }
        void preorder(int i){
            if(i<size){
                cout<<arr[i]<<" ";
                preorder(2*i+1);
                preorder(2*i+2);
            }
        }
        void postorder(int i){
            if(i<size){
                postorder(2*i+1);
                postorder(2*i+2);
                cout<<arr[i]<<" ";
            }
        }
        bool left_skewed(int i){
            if(i>=size || arr[i]==-1){
                return true;
            }
            if(arr[2*i+2]!=-1){
                return false;
            }
            return left_skewed(2*i+1);
        }
        bool right_skewed(int i){
            if(i>=size || arr[i]==-1){
                return true;
            }
            if(arr[2*i+1]!=-1){
                return false;
            }
            return right_skewed(2*i+2);
        }
        bool Perfect(int i){
            if(i>=size || arr[i]==-1){
            return true;
        }
        int leftheight=getheight(2*i+1);
        int rightheight=getheight(2*i+2);
        if(abs(leftheight-rightheight)!=0){
            return false;
        }
        return Perfect(2*i+1) && Perfect(2*i+2);
        }
        bool Full(int i){
        if(i>=size || arr[i]==-1){
            return true;
        }
        if(((2*i+1)!=-1 && (2*i+2)==-1) || ((2*i+2)!=-1 && (2*i+1)==-1)){
            return false;
        }
        return Full(2*i+1) && Full(2*i+2);
    }
    bool Balanced(int i){
        if(i>=size || arr[i]==-1){
            return true;
        }
        int leftheight=getheight(2*i+1);
        int rightheight=getheight(2*i+2);
        if(abs(leftheight-rightheight)>1){
            return false;
        }
        return Balanced(2*i+1) && Balanced(2*i+2);
    }
};
int main(){
     BST<int> bst;
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
    bst.Max();
    bst.print();
    cout<<bst.leftSkewed()<<endl;
    cout<<bst.rightSkewed()<<endl;
    cout<<bst.perfect()<<endl;
    cout<<bst.full()<<endl;
    cout<<bst.balanced()<<endl;
}