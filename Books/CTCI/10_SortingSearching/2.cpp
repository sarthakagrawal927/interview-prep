class Solution {
private:

    string getAnag(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
    
    void insertS(string s, vector<vector<string>> &ans, unordered_map<string, vector<string>> &anaList){
        string anag = getAnag(s);
        anaList[anag].push_back(s);

    }
public:

    vector<vector<string>> groupAnagrams(vector<string>& str) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> anaList;

        if(str.size() == 1) {ans.push_back(str); return ans;}
        for(auto s : str){ insertS(s,ans,anaList);}
                for(auto p : anaList){
            ans.push_back(p.second);
        }
        return ans;
    }
};