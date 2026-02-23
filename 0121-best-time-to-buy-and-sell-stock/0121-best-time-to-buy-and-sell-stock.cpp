class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       
       vector<int> diff;
       int d =0;
       for(int i = 0;i<prices.size()-1;i++){
          d = prices[i+1] -prices[i];
          diff.push_back(d);
       } 
       
       int k = 0;
       int max_profit = 0;

       for(int i = 0  ; i<diff.size();i++){
          k = max(diff[i],diff[i]+k) ;
          if(max_profit < k){
            max_profit = k;
          }
       }
       
       return max(0,max_profit);
    }
};