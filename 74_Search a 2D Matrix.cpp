/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
[1,   3,  5,  7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]
Given target = 3, return true.
*/


class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		//������뷵�أ���������matrix[0]�ڿվ���ʱ�޷�����
		if (0 == m) return false; 
		int n = matrix[0].size();//��Ȼ�������е�һάû�еڶ�ά�����
		if (0 == n) return false;

		int high = m*n-1, low = 0;
		while (low < high){
			int mid = (low + high) / 2;
			if (target > matrix[mid / n][mid % n]) low = mid + 1;
			else high = mid;
		}
		//�ҵ���target��������֣��������ıȽϣ�
		//����ó���˼·�Ļ�������һ��Ԫ�ص�����޷��ж�
		return target == matrix[low / n][low % n];
	}
};


/*
���������ȫ���Ե���һ�������ϵ���������
*/
