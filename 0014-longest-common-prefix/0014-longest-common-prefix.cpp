class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string str = "";
        string str1 =strs[0];
        string str2 = strs[strs.size()-1];
        int n = min(str1.size(),str2.size());
        for(int i =0;i<n;i++){
            if(str1[i]!=str2[i]){
                break;
            }else{
                str.push_back(str1[i]);
            }
        }
        return str;
    }
};