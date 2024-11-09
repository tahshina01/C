#include<bits/stdc++.h>
using namespace std;
int a[100000];

int partition(int arr[], int low, int high, int exp)
{
    int element = arr[high];
    int pivot = low;
    for (int i = low; i <= high - 1; i++)
    {
        if ((arr[i] / exp) <= (element / exp) )
        {
            swap(arr[pivot], arr[i]);
            pivot++;
        }
    }
    swap(arr[pivot], arr[high]);
    return pivot;
}

void quickSort(int arr[], int low, int high, int exp)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high, exp);
        quickSort(arr, low, pivot - 1, exp);
        quickSort(arr, pivot + 1, high, exp);
    }
}
int getMax(int a[],int n){
    int max=a[0];
    for(int i=1; i<n; i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}
void radix_sort(int a[],int n){
    int max=getMax(a,n);
    for(int exp=1; max/exp>0; exp=exp*10){
        //insertionSort(a,n,exp);
        //merge_sort(a, 0, n-1, exp);
        quickSort (a, 0, n-1, exp);
        //countingSort(a, n, exp);
        //bucketSort(a,n,exp);
    }
}
int main(){
    freopen("inputshort.txt","r",stdin);
    freopen("outputshort.txt","w",stdout);
int n;
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
radix_sort(a,n);
for(int i=0;i<n;i++){
    cout<<a[i]<<endl;
}

}
