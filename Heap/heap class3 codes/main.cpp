#include <iostream>
#include<vector>
#include<queue>
using namespace std;

class info {
        public:
        int data;
        int row;
        int col;

        info(int val, int r, int c) {
                data = val;
                row = r;
                col = c;
        }  
};




class compare {
        public:
        bool operator()(info* a, info* b) {
                return a->data > b->data;
        }
};




vector<int> mergeKSortedArrays(int arr[][4], int k, int n) {
        priority_queue<info*,vector<info*>, compare > minHeap;

        //hr array ka first element insert karo 
        for(int i=0; i<k; i++) {
                info* temp = new info(arr[i][0], i, 0);
                minHeap.push(temp);
        }

        vector<int> ans;

        while(!minHeap.empty()) {
                info* temp = minHeap.top();
                int topElement = temp->data;
                int topRow = temp->row;
                int topCol = temp->col;
                minHeap.pop();

                ans.push_back(topElement);

                if(topCol + 1 < n) {
                        info* newInfo = new info(arr[topRow][topCol+1], topRow, topCol+1);
                        minHeap.push(newInfo);
                }
        }
        return ans;
}




int main() {
        int arr[][4] = { {2,4,6,8}, 
                        {1,3,5,7}, 
                        {0,9,10,11}
                        };
        int k = 3;
        int n = 4;
        vector<int> ans  = mergeKSortedArrays(arr, k, n);
        for(auto i:ans) {
                cout << i << " ";
        }cout << endl;
  return 0;
}



class Info {
public:
    int element, rowIndex, colIndex;

    Info(int val, int row, int col) {
        element = val;
        rowIndex = row;
        colIndex = col;
    }
};

class compare {
public:
    bool operator()(Info* a, Info* b) {
        return a->element > b->element;
    }
};

class Solution {
public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        priority_queue<Info*, vector<Info*>, compare> pq;
        vector<int> ans;
        
        for(int i = 0; i < K; i++) {
            Info* temp = new Info(arr[i][0], i, 0);
            pq.push(temp);
        }
        
        while(!pq.empty()) {
            Info* front = pq.top();
            pq.pop();
            ans.push_back(front->element);
            
            if(front->colIndex + 1 < arr[front->rowIndex].size()) {
                int element = arr[front->rowIndex][front->colIndex + 1];
                pq.push(new Info(element, front->rowIndex, front->colIndex + 1));
            }
        }
        
        return ans;
    }
};


2. Merging K Sorted Linked Lists
A similar application of heaps is in merging multiple sorted linked lists:


class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        ListNode* head = NULL;
        ListNode* tail = NULL;

        for(ListNode* list : lists) {
            if(list) pq.push(list);
        }

        while(!pq.empty()) {
            ListNode* front = pq.top();
            pq.pop();
            
            if(!head) {
                head = front;
                tail = front;
            } else {
                tail->next = front;
                tail = front;
            }
            
            if(front->next) pq.push(front->next);
        }

        return head;
    }
};




3. Smallest Range in K Lists
This problem involves finding the smallest range that includes at least one element from each of the k lists:



class Info {
public:
    int data, rIndex, cIndex;
    Info(int val, int r, int c) : data(val), rIndex(r), cIndex(c) {}
};

class compare {
public:
    bool operator()(Info* a, Info* b) { 
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*, vector<Info*>, compare> pq;
        int maxi = INT_MIN, mini = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(new Info(nums[i][0], i, 0));
            maxi = max(maxi, nums[i][0]);
        }
        
        int ansStart = 0, ansEnd = INT_MAX;
        
        while(!pq.empty()) {
            Info* front = pq.top();
            pq.pop();
            mini = front->data;

            if((maxi - mini) < (ansEnd - ansStart)) {
                ansStart = mini;
                ansEnd = maxi;
            }
            
            if(front->cIndex + 1 < nums[front->rIndex].size()) {
                int element = nums[front->rIndex][front->cIndex + 1];
                maxi = max(maxi, element);
                pq.push(new Info(element, front->rIndex, front->cIndex + 1));
            } else break;
        }

        return {ansStart, ansEnd};
    }
};



4. Median of a Data Stream
Finding the median of a data stream involves maintaining two heaps — 
a max-heap for lower half numbers and a min-heap for upper half numbers:


class MedianFinder {
public:
    priority_queue<int> maxHeap; // Max-Heap
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-Heap

    void addNum(int num) {
        if(maxHeap.size() == minHeap.size()) {
            if(num > findMedian()) minHeap.push(num);
            else maxHeap.push(num);
        } else if(maxHeap.size() > minHeap.size()) {
            if(num > findMedian()) minHeap.push(num);
            else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
        } else {
            if(num <= findMedian()) maxHeap.push(num);
            else {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
        }
    }

    double findMedian() {
        if(maxHeap.empty() && minHeap.empty()) return 0.0;
        if(maxHeap.size() == minHeap.size()) 
            return (maxHeap.top() + minHeap.top()) / 2.0;
        if(maxHeap.size() > minHeap.size()) 
            return maxHeap.top();
        return minHeap.top();
    }
};