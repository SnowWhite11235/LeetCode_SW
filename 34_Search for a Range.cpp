/*
Given an array of integers sorted in ascending order, find the starting and ending position of 
a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

*/

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int n = nums.size();
		vector<int> res(2, -1);
		if (0 == n) return res;
		int low = 0, high = n - 1;

		while (low<high){
			int mid = (low + high) / 2;
			if (nums[mid] < target) low = mid + 1;
			else high = mid;
		}
		if (nums[low] != target) return res; //因为这里会用到索引，所以要检查索引的有效性
		else res[0] = low;

		high = n - 1;
		while (low<high){
			int mid = (low + high) / 2 + 1; // 确保偏向high
			if (nums[mid] > target) high = mid - 1;
			else low = mid;
		}
		res[1] = high;
		return res;
	}
};

/*
二分法:
分别找左右端点,因为两个logn加在一起还是logn

注意：寻找右端点的时候+1，原因是int向下取整，当low和high相邻的时候，永远只能取到low，陷入死循环。
When we use mid = (i+j)/2, the mid is rounded to the lowest integer.
But for the new j, it is okay if we set it to mid, since it was not equal to mid anyways. 
Our two rules in search of the left boundary happen to satisfy these requirements, 
so it works perfectly in that situation. Similarly, when we search for the right boundary, 
we must make sure i won't get stuck when we set the new i to i = mid. The easiest way to
achieve this is by making mid biased to the right, i.e. mid = (i+j)/2+1.
*/