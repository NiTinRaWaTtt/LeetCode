class Solution {
public:

    vector<int> findnse(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findpse(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    vector<int> findnge(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

    vector<int> findpge(vector<int>& nums) {
        int n = nums.size();
        vector<int> pge(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }

    long long sumMin(vector<int>& nums){
        vector<int> nse = findnse(nums);
        vector<int> pse = findpse(nums);

        long long sum = 0;

        for(int i = 0; i < nums.size(); i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;

            sum += (left * right * 1LL * nums[i]);
        }
        return sum;
    }

    long long sumMax(vector<int>& nums){
        vector<int> nge = findnge(nums);
        vector<int> pge = findpge(nums);

        long long sum = 0;

        for(int i = 0; i < nums.size(); i++){
            long long left = i - pge[i];
            long long right = nge[i] - i;

            sum += (left * right * 1LL * nums[i]);
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumMax(nums) - sumMin(nums);
    }
};