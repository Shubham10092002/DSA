
Method                          Syntax                                                               Usage
Struct Comparator             struct Compare { bool operator()(T a, T b) { ... } };                  Custom sorting for objects or complex conditions
Lambda Comparator             auto cmp = [](T a, T b) { return a > b; };                             Quick inline custom sorting
Built-in greater<int>         priority_queue<int, vector<int>, greater<int>> pq;                     Min-Heap for simple types
Custom Object Comparator      struct Compare { bool operator()(Object a, Object b) { ... } };        Sorting custom structs/classes
Multi-Condition Comparator    bool operator()(pair<int, int> a, pair<int, int> b) { ... }            Sorting by multiple attributes








#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Custom comparator (Min-Heap)
struct Compare {
    bool operator()(int a, int b) {
        return a > b; // Min-Heap: higher values have lower priority
    }
};

int main() {
    priority_queue<int, vector<int>, Compare> pq;
    
    pq.push(5);
    pq.push(1);
    pq.push(10);
    
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    
    return 0;
}






auto cmp = [](int a, int b) { return a > b; };
priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);


#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    auto cmp = [](int a, int b) { return a > b; };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    pq.push(5);
    pq.push(1);
    pq.push(10);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}







priority_queue<int, vector<int>, greater<int>> pq;
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(5);
    pq.push(1);
    pq.push(10);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}









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












struct ComparePairs {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) 
            return a.first > b.first; // Sort by first element (ascending)
        return a.second > b.second;   // If equal, sort by second (ascending)
    }    
};









priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePairs> pq;

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ComparePairs {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) 
            return a.first > b.first; // Sort by first value (ascending)
        return a.second > b.second;   // If first values are equal, sort by second
    }
};

int main() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePairs> pq;

    pq.push({3, 5});
    pq.push({1, 7});
    pq.push({3, 2});
    pq.push({2, 8});

    while (!pq.empty()) {
        cout << "(" << pq.top().first << ", " << pq.top().second << ") ";
        pq.pop();
    }

    return 0;
}
