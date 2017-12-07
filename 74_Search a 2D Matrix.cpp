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
		//这里必须返回，否则后面的matrix[0]在空矩阵时无法索引
		if (0 == m) return false; 
		int n = matrix[0].size();//居然还存在有第一维没有第二维的情况
		if (0 == n) return false;

		int high = m*n-1, low = 0;
		while (low < high){
			int mid = (low + high) / 2;
			if (target > matrix[mid / n][mid % n]) low = mid + 1;
			else high = mid;
		}
		//找到与target最近的数字，再做最后的比较；
		//如果用常规思路的话，对于一个元素的情况无法判断
		return target == matrix[low / n][low % n];
	}
};


/*
这个条件完全可以当成一个向量上的搜索问题
*/
