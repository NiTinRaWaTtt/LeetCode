class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> shuffle;
        int i = 0;
        int j =n;
    while(i<n||j<nums.size()){
       shuffle.push_back(nums[i]);
       i++;
       shuffle.push_back(nums[j]);
       j++;
    } 
        return shuffle;
    }
};