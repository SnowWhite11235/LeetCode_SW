/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.


*/

class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.size() == 0) return -1; //空列表
		int low = 0;
		int high = nums.size() - 1;

		//特殊情况2:已经排好顺序，减少运算
		if (nums[low]<nums[high]) return nums[low];

		while (low < high){
			int mid = (low + high) / 2;
			//注意此处：low=mid+1 否则可能会陷入死循环，因为除号自带向下取整
			//         判断条件是>=，解决了两个元素的特殊情况3
			if (nums[mid] >= nums[0]) low = mid + 1;
			else high = mid;
		}
		return nums[low];
	}
};

/*
#1 (暴力) n
#2 经典二分法 logn 注意循环条件和比较条件
注意：树状思维：没有元素，一个元素，两个元素，奇数个元素，偶数个元素
if...else的取等要单独拿出来考虑
*/