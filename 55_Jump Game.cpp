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
误区：
需要画示意图；
给出的是最远跳动距离，在此范围内都可以，不要当成固定的，因此每一位都要考虑到，不能只走某一条跳动路径；
不只有一种跳动路径；

无法继续的条件是： i>reach (也就是说，reach不到了i的位置)

解法巧妙！！

*/

bool canJump(vector<int>& nums) {
	int last = nums.size()-1, i;
	for (i = nums.size() - 2; i >= 0; i--){
		if (i + nums[i] >= last) last = i; //倒序：能到达，更新尾部位置
	}
	return last <= 0;
}