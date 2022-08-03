class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       unordered_set<int> un;
        for (int i = 0; i < nums.size(); i++)
        {
            if (un.find(nums[i]) != un.end())
            {
                return true;
            }
            else
            {
                un.insert(nums[i]);
            }
        }
        return false;
    }
};