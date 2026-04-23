class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int count = 0, target = 0;

        while (right < nums.size()) {
            if (nums[right] % 2 == 1) {
                count++;
            }

            while (count > k) {
                if (nums[left] % 2 == 1) {
                    count--;
                }
                left++;
            }

            target += (right - left + 1);
            right++;
        }

        return target;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};