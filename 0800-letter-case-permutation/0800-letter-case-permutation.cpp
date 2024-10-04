class Solution
{
    public:
        vector<string> res;
    vector<string> letterCasePermutation(string s)
    {
       	transform(s.begin(), s.end(),s.begin(), ::tolower);
       	res.push_back(s);
        backtrack(s, 0);
        return res;
    }
    void backtrack(string &nums, int index)
    {
        if (index >= nums.size())
        {
           	// res.push_back(nums);
            return;
        }
        for (int i = index; i < nums.length(); i++)
        {
            if (!isalpha(nums[i])) continue;

            transform(nums.begin() + i, nums.begin() + i + 1, nums.begin() + i, ::toupper);
            res.push_back(nums);
            backtrack(nums, i+ 1);
            transform(nums.begin() + i, nums.begin() + i + 1, nums.begin() + i, ::tolower);
            // res.push_back(nums);
        }
    }
};