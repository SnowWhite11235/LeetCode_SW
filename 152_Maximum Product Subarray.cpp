/*
Find the contiguous subarray within an array(containing at least one number) which has the largest product.

For example, given the array[2, 3, -2, 4],
the contiguous subarray[2, 3] has the largest product = 6.
*/

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int maxVal = nums[0];
		int minCurr = nums[0];
		int maxCurr = nums[0];
		for (int i = 1; i<nums.size(); i++){ //注意初始条件，从第二个数起
			if (nums[i]<0) swap(minCurr, maxCurr);

			minCurr = min(nums[i], minCurr*nums[i]);
			maxCurr = max(nums[i], maxCurr*nums[i]);

			maxVal = max(maxCurr, maxVal);
		}
		return maxVal;
	}
};

/*
#1 (暴力) n^3
#2 n
核心:如果只考虑所有元素为正的情况，max=pre*curr(pre>=1)或者curr(pre<1)，
这个问题需要好好理解，就是说“任何时候我们不需要乘积小于1的子序列”，
一旦出现，就保留之前的最大乘积的结果，并refresh。

对于乘法累积来说，min max都要存，因为可能会有负数，这时候就要交换min max；

*/