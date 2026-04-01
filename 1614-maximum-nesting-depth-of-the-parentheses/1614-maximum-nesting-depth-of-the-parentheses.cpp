class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxc =0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                count++;
                maxc = max(count,maxc);
            }
            else if(s[i]==')'){
                count--;
            }
        }
        return maxc;
    }
};