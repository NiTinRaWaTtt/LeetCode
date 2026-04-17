class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        int maxA = 0;
        stack<int> st;
        for(int i =0;i<=heights.size();i++){
            while(!st.empty() &&(i==heights.size() ||heights[st.top()]>=heights[i])){
                int height = heights[st.top()]; st.pop();
                int width;
                if(st.empty()){
                    width = i;
                }else{
                 width = i-st.top()-1;
                } maxA = max(maxA,width*height);
            }
            st.push(i);   
        }
        return maxA;

    }
};