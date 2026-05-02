class Solution {
private:
    string isPalindrome(string s) {
        if (s.size()%2) { //odd
            string second = s.substr(s.size()/2+1);
            reverse(second.begin(),second.end());
            if (s.substr(0,s.size()/2) == second) {
                return s;
            } else return "";
        } else { //even
            string second = s.substr(s.size()/2);
            reverse(second.begin(),second.end());
            if (s.substr(0,s.size()/2) == second) {
                return s;
            } else return "";
        }
    }
public:
    string longestPalindrome(string s) {
        queue<string> q;
        q.push(s);
        int counter = 0;
        string curr;
        string pali;

        while (!q.empty()){
            curr = q.front();
            q.pop();
            pali = isPalindrome(curr);
            //cout << "Checking: " << curr << " result: " << pali << endl;
            if (pali!="") return pali;
            if (!q.empty()) continue;
            else {
                counter++;
                if (counter==s.size()) return "";
                for (int i=0;i<=counter;i++){
                    string newS = s.substr(i,s.size()-counter);
                    //cout << newS << endl;
                    q.push(newS);
                }
            } 
        }
        return "";
    }
};
