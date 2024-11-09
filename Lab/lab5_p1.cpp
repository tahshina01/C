#include<bits/stdc++.h>
using namespace std;
template<typename T>
class PriorityQueue {
    private:
    vector<T> heap_;
public:
    void push(T value) {
        heap_.push_back(value);
        int i = heap_.size() - 1;
        while (i > 0 && heap_[i] > heap_[(i - 1) / 2]) {
            swap(heap_[i], heap_[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    T pop() {
        T result = heap_[0];
        heap_[0] = heap_[heap_.size() - 1];
        heap_.pop_back();

        int i = 0;
        while (2 * i + 1 < heap_.size()) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (heap_[left] > heap_[largest]) {
                largest = left;
            }

            if (right < heap_.size() && heap_[right] > heap_[largest]) {
                largest = right;
            }

            if (largest != i) {
                swap(heap_[i], heap_[largest]);
                i = largest;
            } else {
                break;
            }
        }
        

        return result;
    }
    T top(){
            return heap_[heap_.size()-1];
    }
    bool empty() const {
        return heap_.empty();
    }


};
int minRefuelStops(int target, int startFuel, int arr[][2],int size) {
        int sf = startFuel;
        int n =size;
        int ans=0;
        int i=0;
        if(target<=startFuel)
            return 0;
        PriorityQueue<int> pq;
        while(sf<target)
        {
            while(i<n && arr[i][0]<=sf)
            {
                pq.push(arr[i][1]);
                i++;
            }
            if(pq.empty())
                return -1;
            int mx = pq.top();
            pq.pop();
            sf+= mx;
            ans++;
        }
        return ans;
    }

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
   int target,startfuel,n;
   cin>>target>>startfuel>>n;
   int vec[n+3][2];
   for(int i=0;i<n;i++){
    for(int j=0;j<2;j++){
        cin>>vec[i][j];
    }
        
   }
   cout<<minRefuelStops(target,startfuel,vec,n)<<endl;
   


}