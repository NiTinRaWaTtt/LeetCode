class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        auto rickshaw = max_element(arr.begin(), arr.end());
        int index = rickshaw - arr.begin();
        return index;
    }

};