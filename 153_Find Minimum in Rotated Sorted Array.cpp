/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.


*/

class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.size() == 0) return -1; //���б�
		int low = 0;
		int high = nums.size() - 1;

		//�������2:�Ѿ��ź�˳�򣬼�������
		if (nums[low]<nums[high]) return nums[low];

		while (low < high){
			int mid = (low + high) / 2;
			//ע��˴���low=mid+1 ������ܻ�������ѭ������Ϊ�����Դ�����ȡ��
			//         �ж�������>=�����������Ԫ�ص��������3
			if (nums[mid] >= nums[0]) low = mid + 1;
			else high = mid;
		}
		return nums[low];
	}
};

/*
#1 (����) n
#2 ������ַ� logn ע��ѭ�������ͱȽ�����
ע�⣺��״˼ά��û��Ԫ�أ�һ��Ԫ�أ�����Ԫ�أ�������Ԫ�أ�ż����Ԫ��
if...else��ȡ��Ҫ�����ó�������
*/