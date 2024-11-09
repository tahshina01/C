#include<bits/stdc++.h>
using namespace std;
void heapify(int heap[],int size, int i){
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
            heapify(heap, size, largest);
        }
    }
    
    void heapsort(int heap[],int size){
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(heap, size, i);
    }

    for (int i = size - 1; i >= 0; i--) {
        swap(heap[0], heap[i]);
        heapify(heap, i, 0);
    }

    }
    int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n=sizeof(arr)/sizeof(arr[0]);
    heapsort(arr,n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}