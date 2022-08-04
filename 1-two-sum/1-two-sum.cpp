class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> un;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = un.find(target - nums[i]);
            if (it != un.end())
            {
                return vector<int> {i, it->second};
            }
            else
            {
                un[nums[i]] = i;
            }
        }
        return {};
    }
};