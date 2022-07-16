class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> vt;
        int sum = nums[0];
        vt.push_back(sum);
        for (int i = 1; i < nums.size(); i++)
        {
            sum += nums[i];
            vt.push_back(sum);
        }
        return vt;
    }
};