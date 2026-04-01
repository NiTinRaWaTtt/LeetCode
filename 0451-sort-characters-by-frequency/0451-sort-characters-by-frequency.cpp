class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;

        // Count frequency
        for (auto i : s) {
            mp[i]++;
        }

        // Bucket sort
        vector<vector<char>> ds(s.size() + 1);

        for (auto it : mp) {
            int freq = it.second;
            char ch = it.first;
            ds[freq].push_back(ch);
        }

        string ans = "";

    
        for (int i = s.size(); i >= 1; i--) {
            for (auto ch : ds[i]) {
                ans.append(i, ch);   
            }
        }

        return ans;
    }
};