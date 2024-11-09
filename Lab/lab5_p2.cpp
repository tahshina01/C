#include <iostream>
#include <queue>
#include <vector>

std::queue<int> longestSubsequence(std::queue<int> q, int target) {
    std::queue<int> window;
    std::queue<int> longest;

    int sum = 0;
    int maxLength = 0;

    while (!q.empty()) {
        int next = q.front();
        q.pop();

        if (sum + next <= target) {
            sum += next;
            window.push(next);
        } else if (!window.empty()) {
            sum -= window.front();
            window.pop();
        }

        if (sum <= target && window.size() > maxLength) {
            maxLength = window.size();
            longest = window;
        }
    }

    return longest;
}

int main() {
    std::queue<int> q({3, 4, 1, 2, 5, 7, 8});
    int target = 12;

    std::queue<int> result = longestSubsequence(q, target);

    std::cout << "Longest subsequence: ";
    while (!result.empty()) {
        std::cout << result.front() << " ";
        result.pop();
    }
    std::cout << std::endl;

    return 0;
}
