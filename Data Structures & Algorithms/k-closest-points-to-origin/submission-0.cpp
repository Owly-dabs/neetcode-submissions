class Compare {
public:
    bool operator()(vector<int> a, vector<int> b) {
        double eucDistA = sqrt(a[0]*a[0] + a[1]*a[1]);
        double eucDistB = sqrt(b[0]*b[0] + b[1]*b[1]);

        if (eucDistA > eucDistB) return true;
        return false;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> heap;

        for (vector<int> v:points) {
            heap.push(v);
        }

        vector<vector<int>> out;
        for (int i = 0; i < k; i++) {
            out.push_back(heap.top());
            heap.pop();
        }

        return out;
    }
};
