class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int maxSum = nums[0];
		int currentSum = 0;
		for (int x : nums) {
			currentSum = max(x, currentSum + x);
			maxSum = max(maxSum, currentSum);
		}
		return maxSum;
	}
};