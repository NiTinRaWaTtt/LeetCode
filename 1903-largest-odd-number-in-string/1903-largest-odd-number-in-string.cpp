class Solution {
public:
    string largestOddNumber(string num) {
        int last = num[num.size()-1];
        if(last%2!=0){
            return num;
        }
        string ans;
        for(int i=num.size()-2; i>=0; i--){
            if(num[i]%2!=0){
                ans += num.substr(0, i+1);
                break;
            }
        }
        return ans;
    }
};