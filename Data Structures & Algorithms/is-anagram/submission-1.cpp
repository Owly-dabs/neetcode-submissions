class Solution {
public:
    bool isAnagram(string s, string t) {
        // check if lengths is same
        if (s.size() != t.size()) {
            return false;
        }

        // make hashmap for s
        unordered_map<char,int> map;
        for (char c : s) {
            map[c]++;
        }

        // Use hashmap to check against t
        for (char c : t) {
            if (--map[c] < 0) {
                return false;
            }
        }

        return true;
    }
};
