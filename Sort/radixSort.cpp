#include <bits/stdc++.h>
#include <ctime>
using namespace std;
int getMax(int a[],int n){
    int max=a[0];
    for(int i=1; i<n; i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}

void countingSort(int arr[], int n, int exp)
{
    int count[10];
    int output[n];

    for (int i = 0; i <= 9; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i <= 9; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void insertionSort(int arr[], int n, int exp)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int t = arr[i];
        while (j >= 0 && (arr[j] / exp) % 10 > (t / exp) % 10)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = t;
    }
}

int partition(int arr[], int low, int high, int exp)
{
    int element = arr[high];
    int pivot = low;
    for (int i = low; i <= high - 1; i++)
    {
        if ((arr[i] / exp) <= (element / exp))
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
int  N=5000;


void append(int ar[],int l, int r, int m,int exp){
    int temp[r-l+1];
    int i=l;
    int j=m+1;
    int k=0;
    while(i<=m and j<=r){
        if((ar[i]/exp)%10<=(ar[j]/exp)%10){
            temp[k]=ar[i];
            i++;
        }
        else{
            temp[k]=ar[j];
            j++;
        }
        k++;
    }
    while(i<=m){
        temp[k]=ar[i];
        i++;
        k++;
    }
    while(j<=r){
        temp[k]=ar[j];
        j++;
        k++;
    }
    for(int i=l;i<=r;i++){
        ar[i]=temp[i-l];
    }

}
void merge_sort(int ar[],int l, int r,int exp){
    if(l<r){
        int m=(l+r)/2;
        merge_sort(ar,l,m,exp);
        merge_sort(ar,m+1,r,exp);
        append(ar,l,r,m,exp);
    }
}


    int v[3][500000];
void bucketSort(int ar[],int n, int exp){

    int a=0,b=0,c=0;
    for(int i=0;i<n;i++){

        int z=(ar[i]/exp)%10;

        if(z<=3){
            v[0][a]=ar[i];
            a++;
        }
        else if(z<=6){
            v[1][b]=ar[i];
            b++;
        }
        else{
            v[2][c]=ar[i];
            c++;
        }

    }
    int k=0;
    if(a!=0){
        merge_sort(v[0],0,a-1,exp);
        for(int i=0;i<a;i++){
            ar[k]=v[0][i];
            k++;
        }
    }
    if(b!=0){
        merge_sort(v[1],0,b-1,exp);
        for(int i=0;i<b;i++){
            ar[k]=v[1][i];
            k++;
        }
    }
    if(c!=0){
        merge_sort(v[2],0,c-1,exp);
        for(int i=0;i<c;i++){
            ar[k]=v[2][i];
            k++;
        }
    }


}
void radix_sort(int a[],int n){
    int max=getMax(a,n);
    for(int exp=1; max/exp>0; exp=exp*10){
        //insertionSort(a,n,exp);
        //merge_sort(a, 0, n-1, exp);
        //quickSort(a, 0, n-1, exp);
        //countingSort(a, n, exp);
        bucketSort(a,n,exp);
    }
}






int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    time_t st;
    int n = 7000;
    int arr[n];

    for (int j = 0; j < n; j++)
    {
        int temp;
        cin >> temp;
        arr[j] = temp;
    }
        st = clock();
      radix_sort(arr,n);
      long long int t1 = clock() - st;
      cout <<" time "<< t1 << endl;

    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
        if((j+1)%7==0){
            cout<<endl;
        }
    }
    cout << endl;



    return 0;
}
