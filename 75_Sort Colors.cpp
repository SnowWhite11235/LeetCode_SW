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
			while (nums[i] == 2 && i<twoPt) swap(nums[i], nums[twoPt--]);   //���1
			while (nums[i] == 0 && i>zeroPt) swap(nums[i], nums[zeroPt++]); //���2
		}
	}
};

/*
��鵱ǰλ�ÿ�ʼ�Ƿ���0��2���оͻ��ߣ�
ע��˴���ǰ����������������ģ���0ָ��ָ������ݶԵ�ֻ�ܻ�����1���Ѿ�cover��λ�ã���
����2ָ��ָ������ݶԵ�ʲô���п��ܣ�if2�����ж����1��ֱ������2�ˣ���ôif0�����ж����2��if1ά�ֲ�����
Ҳ����˵forѭ����ÿ��iter���iλ��һ������һ��1

վ���Ժ��ĳһʱ�����������̣�д��ͨ�õ��㷨���ټ����β�Ƿ�����������
*/