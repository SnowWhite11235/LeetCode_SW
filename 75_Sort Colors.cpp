/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color 
are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number 
of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/


class Solution {
public:
	void sortColors(vector<int>& nums) {
		int zeroPt = 0, twoPt = nums.size() - 1;
		for (int i = 0; i <= twoPt; i++) {
			while (nums[i] == 2 && i<twoPt) swap(nums[i], nums[twoPt--]);   //语句1
			while (nums[i] == 0 && i>zeroPt) swap(nums[i], nums[zeroPt++]); //语句2
		}
	}
};

/*
检查当前位置开始是否有0和2，有就换走；
注意此处往前换和往后换是有区别的，与0指针指向的内容对调只能换回来1（已经cover的位置），
但与2指针指向的内容对调什么都有可能，if2继续判断语句1，直到不是2了，那么if0继续判断语句2，if1维持不动，
也就是说for循环的每个iter最后i位置一定留下一个1

站在以后的某一时刻想整个过程，写出通用的算法，再检查首尾是否满足条件。
*/