/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0 ? 
Find all unique triplets in the array which gives the sum of zero.

Note : The solution set must not contain duplicate triplets.

	   For example, given array S = [-1, 0, 1, 2, -1, -4],

	   A solution set is :
[
	[-1, 0, 1],
	[-1, -1, 2]
]
*/

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int> > res;
		std::sort(nums.begin(), nums.end());

		for (int i = 0; i<nums.size(); i++){
			int tar = -nums[i];
			int low = i + 1;
			int high = nums.size() - 1;

			vector<int> triplet(3, 0);

			while (low<high){
				if (nums[low] + nums[high] < tar) low++;
				else if (nums[low] + nums[high] > tar) high--;
				else{
					triplet[0] = nums[i];
					triplet[1] = nums[low];
					triplet[2] = nums[high];

					res.push_back(triplet);

					while (triplet[1] == nums[low + 1] && low<high) low++;
					while (triplet[2] == nums[high - 1] && low<high) high--;
					low++; high--;
				}
			}
			while (i<nums.size() - 1 && nums[i] == nums[i + 1]) i++;
		}
		return res;
	}
};

/*
#1 (����) n^3
#2 n^2
ת��Ϊ�������⣬�����Ѷ���������������
�������������󣬿���������ָ��ͬʱ�����߿�ʼ��������ѭ����Ϊһ�㣻
С�Ĵ����Թ��ظ�Ԫ�صĹ�����
ע�����ﲻ����ȥ���ظ�Ԫ�أ����� -1 -1 2��������Ͼͻᱻ��©��

ifֻ����һ�������жϣ�while���кܶ�Ρ���
*/