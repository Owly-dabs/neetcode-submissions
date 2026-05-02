class Solution {
public:
    bool isPalindrome(string s) {
        // init pointers
        int j = s.size() - 1;
        int i = 0;

        while (i < j) {
            if (!std::isalnum(s[i])) {
                i++;
                continue;
            } else if (!std::isalnum(s[j])) {
                j--;
                continue;
            } else {
                if (std::tolower(s[i]) != std::tolower(s[j])) return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
