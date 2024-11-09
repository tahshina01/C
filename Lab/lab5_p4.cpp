#include <iostream>
#include <queue>

void printMaxOfSubarrays(int arr[], int n, int k) {
    std::deque<int> dq(k);

    int i;
    for (i = 0; i < k; i++) {
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for (; i < n; i++) {
        std::cout << arr[dq.front()] << " ";

        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    std::cout << arr[dq.front()] << std::endl;
}

int main() {
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    printMaxOfSubarrays(arr, n, k);

    return 0;
}
