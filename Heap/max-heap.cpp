#include<bits/stdc++.h>
using namespace std;
#define MAX 500
template<typename T> 
class Maxheap{
 private:
    int heap[MAX];
    int i=0;
    int parent(int i){
        return (i-1)/2 ;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }
    int size(){
        return i;
    }
    bool empty(){
        if(i==0){
            return true;
        }
        else return false;
    }
    void heapifyup(int i){
        if(i && heap[parent(i)]<heap[i]){
            swap(heap[i],heap[parent(i)]);
            heapifyup(parent(i));
        }
    }
    void heapifydown(int i){
        int highest=i;
        if(left(i)<size() && heap[left(i)]>heap[i]){
            highest=left(i);
        }
        if(right(i)<size() && heap[right(i)]>heap[i]){
            highest=right(i);
        }
        if(highest!=i){
            swap(heap[i],heap[highest]);
            heapifydown(highest);
        }
    }
    public:
    void insert(int value){
        heap[i++]=value;
        int index=Size()-1;
        heapifyup(index);
       
    }
    void deletemax(){
        if(empty()){
            return;
        }
        heap[0]=heap[i-1];
        cout<<heap[0]<<" "<<heap[i-1]<<endl;
        i--;
        heapifydown(0);
    }
    void deleteindx(int j){
        int last=Size()-1;
        swap(heap[last],heap[j]);
        i--;
        heapifydown(j);

    }
    
    int getmax(){
        if(empty()){
            return -1;
        }
        return heap[0];
    }
    int Size(){
        return size();
    }
    void print(){
        for(int i=0;i<Size();i++){
            cout<<heap[i]<<" ";
        }
        cout<<" end "<<endl;
    }
    void inorder(int i){
            if(i<Size()){
                inorder(2*i+1);
                cout<<heap[i]<<" ";
                inorder(2*i+2);
            }
    }
    int peek(){
        return heap[0];
    }
    int extract(){
        if(empty()){
            return -1;
        }
        int val=heap[0];
        heap[0]=heap[i-1];
        i--;
        heapifydown(0);
        return val;
    }
}; 
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
 void heapify_max(int heap[],int size, int i){
        int left=2*i+1;
        int right=2*i+2;
        int largest=i;
        if(left<=size-1 && heap[left]>heap[largest]){
            largest=left;
        }
        if(right<=size-1 && heap[right]>heap[largest]){
            largest=right;
        }
        if(largest!=i){
            swap(heap[largest],heap[i]);
            heapify_max(heap, size, largest);
        }
    }
    void heapify(int heap[], int size){
        for(int i=size/2-1;i>=0;i--){
            heapify_max(heap,size,i);
        }
    }
    void merge(int heap[], int hp[], int merged[], int m, int n ){
        
        int k=0;
        for(int i=0;i<m;i++){
            merged[k]=heap[i];
            k++;
        }
        for(int i=0;i<n;i++){
            merged[k]=hp[i];
            k++;
        }
        heapify(merged, m+n);
    }
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Maxheap<int> heap;
    heap.insert(3);
    heap.insert(9);
    heap.insert(2);
    heap.insert(1);
    heap.insert(4);
    heap.insert(5);
    heap.insert(7);
    cout<<heap.getmax()<<endl;
    heap.print();
    //heap.deletemax();
    heap.print();
    heap.deleteindx(1);
    heap.print();
    cout<<heap.extract()<<endl;
    heap.print();
    int m,n;
    cin>>m>>n;
    int hp[MAX];
    for(int i=0;i<m;i++){
        cin>>hp[i];
    }
    // heapify(hp);
    // for(int i=0;i<5;i++){
    //     cout<<hp[i]<<" ";
    // }
    int hp1[MAX];
    for(int i=0;i<n;i++){
        cin>>hp1[i];
    }
    // heapify(hp1);
    // for(int i=0;i<3;i++){
    //     cout<<hp1[i]<<" ";
    // }
    int merged[m+n];
    merge(hp,hp1,merged,m,n);
    for(int i=0;i<(m+n);i++){
        cout<<merged[i]<<" ";
    }

}