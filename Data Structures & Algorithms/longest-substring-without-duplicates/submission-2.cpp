class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // edge case
        if (s.size() <= 1) return s.size();

        vector<int> lastSeen(96,-1); // char tracker
        int maxLength = 1; // max traacker
        int p = 0; // start pointer
        int ind = s[0] - ' ';
        lastSeen[ind] = 0;

        for (int i = 1; i < s.size(); i++) {
            ind = s[i] - ' ';
            if (lastSeen[ind] != -1 && lastSeen[ind] + 1 > p) {
                // move p to lastSeen[ind] + 1
                p = lastSeen[ind] + 1;
            }
            maxLength = max(maxLength, i-p+1);
            lastSeen[ind] = i;
        }
    
        return maxLength;
    }
};
