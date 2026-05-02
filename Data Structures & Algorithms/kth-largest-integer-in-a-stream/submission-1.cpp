class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap; // root of minHeap is the kth largest
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size()>k) minHeap.pop();
        return minHeap.top();
    }
};
