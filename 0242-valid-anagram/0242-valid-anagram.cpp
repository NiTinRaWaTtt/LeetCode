class Solution {
public:
    bool isAnagram(string s, string t) {
        bool a;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t){
            a = true;
        }else{
            a = false;
        }
        return a;
        
    }
};