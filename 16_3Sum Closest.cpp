/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, 
target.Return the sum of the three integers.You may assume that each input would have exactly one solution.

For example, given array S = { -1 2 1 - 4 }, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		std::sort(nums.begin(), nums.end());
		//注意这里初始化不能写0，后边更新可能会由于提供数据的问题出错
		int ans = nums[0] + nums[1] + nums[2];

		if (nums.size() <= 3) return accumulate(nums.begin(), nums.end(), 0); //特殊情况

		for (int i = 0; i <= nums.size() - 2; i++){
			int j = i + 1;
			int k = nums.size() - 1;

			while (j<k){
				int sum = nums[i] + nums[j] + nums[k];
				if (abs(target - ans) > abs(target - sum)) {
					ans = sum;
					if (ans == target) return ans;
				}
				(sum > target) ? k-- : j++;
			}
		}
		return ans;
	}
};

/*
#1 (暴力) n^3
#2 n^2
还是固定一个数的双指针问题；与3Sum不同的是不需要存储target三元组；
根据sum和target的比较结果决定移动哪个指针；
注意比较的是绝对值，如果遇到ans==target的情况要及时返回；
*/