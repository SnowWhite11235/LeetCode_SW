/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int len = nums.size();
		int reach = 0, i = 0;
		for (; i < len && i <= reach; ++i)
			reach = max(i + nums[i], reach);
		return i == len;
	}
};

/*
������
��Ҫ��ʾ��ͼ��
����������Զ�������룬�ڴ˷�Χ�ڶ����ԣ���Ҫ���ɹ̶��ģ����ÿһλ��Ҫ���ǵ�������ֻ��ĳһ������·����
��ֻ��һ������·����

�޷������������ǣ� i>reach (Ҳ����˵��reach������i��λ��)

�ⷨ�����

*/

bool canJump(vector<int>& nums) {
	int last = nums.size()-1, i;
	for (i = nums.size() - 2; i >= 0; i--){
		if (i + nums[i] >= last) last = i; //�����ܵ������β��λ��
	}
	return last <= 0;
}