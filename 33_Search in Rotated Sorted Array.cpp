/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search.If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

*/

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int n = nums.size();
		int low = 0, high = n - 1;
		while (low<high){
			int mid = (low + high) / 2;
			if (nums[mid]>nums[high]) low = mid + 1;
			else high = mid;
		}
		int rotaPos = low;
		low = 0, high = n - 1;
		while (low <= high){
			int mid = (low + high) / 2;
			int realPos = (mid + rotaPos) % n;
			if (nums[realPos] == target) return realPos;
			else if (nums[realPos]<target) low = mid + 1;
			else high = mid - 1;
		}
		return -1;
	}
};

/*
#1 (����) n
#2 logn
���ַ����ҵ�ͷ��Ȼ���ٶ��ַ��ҵ�target
*/