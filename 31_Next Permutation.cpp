/*
Implement next permutation, which rearranges numbers into the lexicographically next greater 
permutation of numbers.If such arrangement is not possible, it must rearrange it as the lowest 
possible order(ie, sorted in ascending order).

The replacement must be in - place, do not allocate extra memory.

Here are some examples.Inputs are in the left - hand column and its corresponding outputs are 
in the right - hand column.
1, 2, 3 → 1, 3, 2
3, 2, 1 → 1, 2, 3
1, 1, 5 → 1, 5, 1

*/

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int k = -1;
		for (int i = nums.size() - 2; i >= 0; i--){
			if (nums[i + 1]>nums[i]){
				k = i;
				break;
			}
		}
		if (k == -1){ //是按照从小到大排序的
			reverse(nums.begin(), nums.end());
			return;
		}

		int l = -1;
		for (int i = nums.size() - 1; i > k; i--){
			if (nums[i]>nums[k]){
				l = i;
				break;
			}
		}
		swap(nums[k], nums[l]);
		reverse(nums.begin() + k + 1, nums.end());
		return;
	}
};

/*
注意：理清楚怎么做是这道题的重点
case1 是按照从大到小排序的==>改成升序
case2 不是按照降序排序的==>
	总的思路是从低位开始改，变动的位数越少越好（最邻近要求）；
	要把序列变大，要把大的数往前换，小的数往后换；
	就应该在降序（变大要求）的长度为k子序列基础上往前改一位，变成k+1的降序子序列；

因此可以将case1看做是k无限大的情况，先处理；
如果找到了这个k，将它和从后往前第一个比它大的数交换（实现了变大）；然后将k后面的降序子序列变成升序（实现了最邻近）
*/