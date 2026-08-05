#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Task {
    int id;
    int priority;
};

// Custom comparator for Min-Heap (smallest priority first)
struct CompareTask {
    bool operator()(Task const& t1, Task const& t2) {
        return t1.priority > t2.priority;
    }
};

int main() {
    priority_queue<Task, vector<Task>, CompareTask> pq;

    pq.push({1, 3});
    pq.push({2, 1});
    pq.push({3, 2});

    while (!pq.empty()) {
        cout << "Task ID: " << pq.top().id << ", Priority: " << pq.top().priority << endl;
        pq.pop();
    }

    return 0;
}