#include <iostream>
#include <vector>

template<typename T>
class PriorityQueue {
public:
    void push(T value) {
        heap_.push_back(value);
        int i = heap_.size() - 1;
        while (i > 0 && heap_[i] > heap_[(i - 1) / 2]) {
            std::swap(heap_[i], heap_[(i - 1) / 2]);
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
                std::swap(heap_[i], heap_[largest]);
                i = largest;
            } else {
                break;
            }
        }

        return result;
    }

    bool empty() const {
        return heap_.empty();
    }

private:
    std::vector<T> heap_;
};

int main() {
    PriorityQueue<int> pq;
    pq.push(5);
    pq.push(3);
    pq.push(7);
    pq.push(1);

    while (!pq.empty()) {
        std::cout << pq.pop() << " ";
    }
    std::cout << std::endl;

    return 0;
}
