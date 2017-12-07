/*
Implement next permutation, which rearranges numbers into the lexicographically next greater 
permutation of numbers.If such arrangement is not possible, it must rearrange it as the lowest 
possible order(ie, sorted in ascending order).

The replacement must be in - place, do not allocate extra memory.

Here are some examples.Inputs are in the left - hand column and its corresponding outputs are 
in the right - hand column.
1, 2, 3 �� 1, 3, 2
3, 2, 1 �� 1, 2, 3
1, 1, 5 �� 1, 5, 1

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
		if (k == -1){ //�ǰ��մ�С���������
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
ע�⣺�������ô�����������ص�
case1 �ǰ��մӴ�С�����==>�ĳ�����
case2 ���ǰ��ս��������==>
	�ܵ�˼·�Ǵӵ�λ��ʼ�ģ��䶯��λ��Խ��Խ�ã����ڽ�Ҫ�󣩣�
	Ҫ�����б��Ҫ�Ѵ������ǰ����С�������󻻣�
	��Ӧ���ڽ��򣨱��Ҫ�󣩵ĳ���Ϊk�����л�������ǰ��һλ�����k+1�Ľ��������У�

��˿��Խ�case1������k���޴��������ȴ���
����ҵ������k�������ʹӺ���ǰ��һ�����������������ʵ���˱�󣩣�Ȼ��k����Ľ��������б������ʵ�������ڽ���
*/