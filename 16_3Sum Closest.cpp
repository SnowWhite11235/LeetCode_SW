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
		//ע�������ʼ������д0����߸��¿��ܻ������ṩ���ݵ��������
		int ans = nums[0] + nums[1] + nums[2];

		if (nums.size() <= 3) return accumulate(nums.begin(), nums.end(), 0); //�������

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
#1 (����) n^3
#2 n^2
���ǹ̶�һ������˫ָ�����⣻��3Sum��ͬ���ǲ���Ҫ�洢target��Ԫ�飻
����sum��target�ıȽϽ�������ƶ��ĸ�ָ�룻
ע��Ƚϵ��Ǿ���ֵ���������ans==target�����Ҫ��ʱ���أ�
*/