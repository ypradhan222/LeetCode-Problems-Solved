class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int main = -1;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                main = i - 1;
                break;
            }
        }
        if (main != -1) {
            int swap_idx = -1;
            for (int i = n - 1; i > main; i--) {
                if (nums[i] > nums[main]) {
                    swap_idx = i;
                    break;
                }
            }
            swap(nums[main], nums[swap_idx]);
        }
        reverse(nums.begin() + main + 1, nums.end());
    }
};
