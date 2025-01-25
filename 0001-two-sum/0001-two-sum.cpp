class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> indexed_nums;

        for (int i = 0; i < nums.size(); i++) {
            indexed_nums.push_back({nums[i], i});
        }
        sort(indexed_nums.begin(), indexed_nums.end());

        int i = 0, j = indexed_nums.size() - 1;
        while (i < j) {
            int sum = indexed_nums[i].first + indexed_nums[j].first;

            if (sum == target) {
                return {indexed_nums[i].second, indexed_nums[j].second};
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }

        return {}; 
    }
};
