class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> map(26,0);
        for (char c:tasks) {
            map[c-'A']++;
        }
        priority_queue<int> maxHeap;
        for (int t:map) {
            if (t!=0) maxHeap.push(t);
        }

        queue<pair<int,int>> q;
        int time = 0;
        while (!maxHeap.empty() || !q.empty()) {
            time++;

            if (maxHeap.empty()) {
                time = q.front().second;
            } else {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if (cnt>0) q.push({cnt,time+n});
            }

            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
