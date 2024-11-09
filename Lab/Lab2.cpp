#include<bits/stdc++.h>
#include<chrono>

using namespace std;
const int N=1e9+7;
typedef long long int ll;

void countS(int a[], int n, int pos){
    int cnt[10]={0};
    int b[n];
    for(int i=0;i<n;i++){
        ++cnt[(a[i]/pos)%10];
    } for(int i=1;i<10;i++){
        cnt[i]=cnt[i]+cnt[i-1];
    } for(int i=n-1;i>=0;i--){
        b[--cnt[(a[i]/pos)%10]]=a[i];
    } for(int i=0;i<n;i++){
        a[i]=b[i];
    }
}

void selectionS(int a[], int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]) min=j;
        } if(min!=i) swap(a[i],a[min]);
    }
}

void merge(int a[], int lb, int mid, int ub) {
    int n1 = mid - lb + 1;
    int n2 = ub - mid; 
    int L[n1], R[n2];   
    for(int i = 0; i < n1; i++){
        L[i] = a[lb + i];
    } for (int j = 0; j < n2; j++){
        R[j] = a[mid + 1 + j];
	}
    int i=0, j=0, k=lb;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
                j++;
        } k++;
    }
    while (i < n1) {
        a[k] = L[i];
            i++;
            k++;
    }
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeS(int a[], int lb, int ub) {
    if (lb < ub) {
        int m = (lb+ub) / 2;
        mergeS(a, lb, m);
        mergeS(a, m + 1, ub);
        merge(a, lb, m, ub);
    }
}

int partiton(int a[],int lb, int ub){
    int pvt=a[lb], strt=lb, end=ub;
    while(strt<end){
        while(a[strt]<=pvt) strt++;
        while(a[end]>pvt) end--;
        if(strt<end) swap(a[strt], a[end]);
    } swap(a[lb], a[end]);
    return end;
}
void quickS(int a[], int lb, int ub){
    if(lb<ub){
        int loc=partiton(a,lb,ub);
        quickS(a,lb,loc-1);
        quickS(a,loc+1,ub);
    }
}

void radix(int a[],int n){
    int max=*max_element(a,a+n);
    for(int pass=1;(max/pass)>0;pass*=10){
        countS(a,n,pass);
        //selectionS(a,n);
        //mergeS(a,0,n);
        //quickS(a,0,n);
    }
    
}

int main(){
    int n;
    cin>>n;
    int rndmInt[n];
    fstream file1("input.txt",ios::out);
    fstream file2("output.txt",ios::out);
    int p=99999-10000+1;
    for(int i=0;i<n;i++){
        rndmInt[i]=((rand()%p)+10000);
        file1<< rndmInt[i] << " ";
    } file1.close();


    auto start = chrono::high_resolution_clock::now();

    radix(rndmInt,n);
    
    for(int i=0;i<n;i++){
        file2<<rndmInt[i]<<" ";
    } file2<<endl;

    auto end = chrono::high_resolution_clock::now();

    auto time = chrono::duration_cast<chrono::microseconds>(end-start);

    cout << "Total time: "<<time.count() <<" micro sec"<< endl;

    file2.close();
    return 0;
}