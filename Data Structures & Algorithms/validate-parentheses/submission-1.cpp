class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push_back(c);
            }
            else if ( !stack.empty() && c == ')') {
                if (stack.back() == '(') stack.pop_back();
                else return false;
            } 
            else if ( !stack.empty() && c == '}') {
                if (stack.back() == '{') stack.pop_back();
                else return false;
            } 
            else if ( !stack.empty() && c == ']') {
                if (stack.back() == '[') stack.pop_back(); 
                else return false;
            } 
            else if ( stack.empty() && ( c == ')' || c == '}' || c == ']')) return false;
        }

        return stack.empty();
    }
};
