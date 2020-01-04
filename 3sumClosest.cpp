class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        	if (nums.size() < 3) return 0;

	std::sort(nums.begin(), nums.end());
	int diff = target - (nums[0] + nums[1] + nums[2]);
	for (int i = 0; i < nums.size(); ++i) {
		if (i > 0 and nums[i] == nums[i-1]) continue; // skip duplicate
		if (target <= 0 and nums[i] > 0) break; // no point in continuing

		int left = i + 1, right = nums.size() - 1;
		while (left < right) {
			int sum = nums[i] + nums[left] + nums[right];

			if (sum < target) {
				++left;   
			} else if (sum > target) {
				--right;
			} else {
				return target;
			}

			int new_diff = target - sum;
			if (abs(new_diff) < abs(diff)) {
				diff = new_diff;
			}
		}
	}
	return target - diff;
    }
};
