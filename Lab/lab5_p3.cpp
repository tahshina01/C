#include <iostream>
#include <queue>
#include <unordered_map>

std::queue<int> findOrder(int numCourses, std::vector<std::pair<int, int>>& prerequisites) {
    std::queue<int> result;
    std::queue<int> q;
    std::unordered_map<int, std::vector<int>> graph;
    std::vector<int> inDegree(numCourses, 0);

    // Build the graph and compute in-degrees
    for (auto& p : prerequisites) {
        graph[p.second].push_back(p.first);
        ++inDegree[p.first];
    }

    // Add all nodes with in-degree 0 to the queue
    for (int i = 0; i < numCourses; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Topological sort using BFS
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push(node);

        for (int neighbor : graph[node]) {
            --inDegree[neighbor];

            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If there are cycles, the result will not have all courses
    if (result.size() != numCourses) {
        result = std::queue<int>(); // return empty queue to signal failure
    }

    return result;
}

int main() {
    int numCourses = 4;
    std::vector<std::pair<int, int>> prerequisites{{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    std::queue<int> order = findOrder(numCourses, prerequisites);

    if (order.empty()) {
        std::cout << "Cannot finish all courses" << std::endl;
    } else {
        std::cout << "Course order: ";
        while (!order.empty()) {
            std::cout << order.front() << " ";
            order.pop();
        }
        std::cout << std::endl;
    }

    return 0;
}
