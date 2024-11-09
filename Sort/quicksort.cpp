#include<bits/stdc++.h>
using namespace std;
int a[10000];

void print( int n) {
  int i;
  for (i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}
int partition( int low, int high) {
    int pivot = a[low]; // choose first element as pivot
    int i = low + 1; // index for elements less than pivot
    int j = high; // index for elements greater than or equal to pivot
    while (i <= j) {
        if (a[i] < pivot) {
            i++;
        } else if (a[j] >= pivot) {
            j--;
        } else {
            
            // swap arr[i] and arr[j]
            swap(a[i],a[j]);
            
            i++;
            j--;
        }
    }
    // swap pivot with last element in left subarray

    swap(a[low],a[j]);
    

    return j;
}
void quick_sort(int left, int right){

    if(left<right){
        int pivot=partition(left, right);
        quick_sort(left, pivot-1);
        quick_sort(pivot+1, right);
    }
}

int main(){

    freopen("inputsearch.txt","r",stdin);
    freopen("outputsearch.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int left=0;
    int right=n-1;
    quick_sort(left,right);
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }


}


