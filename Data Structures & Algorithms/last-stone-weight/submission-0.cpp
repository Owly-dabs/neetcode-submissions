class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        int x;
        int y;
        int z;
        for (int s:stones) {
            heap.push(s);
        }

        while (heap.size()>1) {
            x = heap.top();
            heap.pop();
            y = heap.top();
            heap.pop();
            if (x!=y) {
                z = x-y;
                heap.push(z);
            }
        }

        if (heap.empty()) return 0;
        return heap.top();
    }
};
