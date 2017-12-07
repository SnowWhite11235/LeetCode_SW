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
		for (int i = 1; i<nums.size(); i++){ //ע���ʼ�������ӵڶ�������
			if (nums[i]<0) swap(minCurr, maxCurr);

			minCurr = min(nums[i], minCurr*nums[i]);
			maxCurr = max(nums[i], maxCurr*nums[i]);

			maxVal = max(maxCurr, maxVal);
		}
		return maxVal;
	}
};

/*
#1 (����) n^3
#2 n
����:���ֻ��������Ԫ��Ϊ���������max=pre*curr(pre>=1)����curr(pre<1)��
���������Ҫ�ú���⣬����˵���κ�ʱ�����ǲ���Ҫ�˻�С��1�������С���
һ�����֣��ͱ���֮ǰ�����˻��Ľ������refresh��

���ڳ˷��ۻ���˵��min max��Ҫ�棬��Ϊ���ܻ��и�������ʱ���Ҫ����min max��

*/