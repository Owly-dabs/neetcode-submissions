class Solution {
public:

    string encode(vector<string>& strs) {
        string out;
        for (string s : strs) {
            out += s;
            out += 0x01;
        }
        return out;
    }

    vector<string> decode(string s) {
        vector<string> out;
        string curr;
        for (char c : s) {
            if (c == 0x01) {
                out.push_back(curr);
                curr = "";
            } else {
                curr += c;
            }
        }
        return out;
    }
};
