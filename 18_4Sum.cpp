/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]
*/
/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]
*/

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		std::sort(nums.begin(), nums.end());
		int n = nums.size();
		vector<vector<int> > ans;
		if (n<4) return ans;

		for (int i = 0; i<n - 3; i++){
			//i>0的条件很重要，确保第一次遇到能参与到计算中，类似[0 0 0 0],0的问题，下同
			if (i>0 && nums[i] == nums[i - 1]) continue;
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3]>target) break;
			if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3]<target) continue;
			for (int j = i + 1; j<n - 2; j++){
				if (j>i + 1 && nums[j] == nums[j - 1]) continue;//j>i+1的条件很重要
				if (nums[i] + nums[j] + nums[j + 1] + nums[i + 2]>target) break;
				if (nums[i] + nums[j] + nums[n - 1] + nums[n - 2]<target) continue;

				int left = j + 1, right = n - 1;
				while (left<right){
					if (nums[i] + nums[j] + nums[left] + nums[right] < target) left++;
					else if (nums[i] + nums[j] + nums[left] + nums[right] > target) right--;
					else{
						ans.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
						left++; right--;
						while (left<right && nums[left] == nums[left - 1]) left++;
						while (left<right && nums[right] == nums[right + 1]) right--;
					}
				}
			}
		}
		return ans;
	}
};

/*
分支循环结构，break和continue的巧妙使用，一方面去掉了极端情况，另一方面解决了重复元素的问题;
别把问题想的太复杂

*/