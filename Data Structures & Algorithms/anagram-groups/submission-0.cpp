class Solution {
public:
    struct VectorHash {
        size_t operator()(const vector<int>& v) const {
            size_t hash = 0;
            for (int i : v) {
                hash ^= std::hash<int>()(i) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<vector<int>, int, VectorHash> stringMaps;
        int uniqueAnagramCount = 0;
        vector<vector<string>> out;
        int charIndex;
        int mapIndex;

        // for each string, make it into a vector
        for (string s:strs){
            vector<int> freq(26,0);

            // make string into hashmap
            for (int i = 0; i < s.size(); i++) {
                charIndex = (int)s[i] - 97;
                freq[charIndex]++;
            }
            // check if hashmap is present in stringMaps. If yes, what's the index?
            if (stringMaps.count(freq)) {
                // get index of map
                mapIndex = stringMaps[freq]; 
                // append to vector in out
                out[mapIndex].push_back(s);
            } else {
                // add new map to stringMaps
                stringMaps[freq] = uniqueAnagramCount;
                uniqueAnagramCount++;
                // push back new vector map to out
                vector<string> n;
                n.push_back(s);
                out.push_back(n);
            }
            // store it in the correct vector out
        }

        return out;
         
    }
};
