/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the
bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

*/

//# 1 
class Solution {
int uniquePaths(int m, int n) {
	vector<vector<int> > path(m, vector<int>(n, 1));
	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
			path[i][j] = path[i - 1][j] + path[i][j - 1];
	return path[m - 1][n - 1];
}
};

//注意此处将第一行和第一列初始化为1，以后也不用变，从(1,1)开始计算
//时间复杂度n^2, 空间复杂度n^2

//# 2
class Solution {
	int uniquePaths(int m, int n) {
		if (m > n) return uniquePaths(n, m);
		vector<int> pre(m, 1);
		vector<int> cur(m, 1);
		for (int j = 1; j < n; j++) {
			for (int i = 1; i < m; i++)
				cur[i] = cur[i - 1] + pre[i];
			swap(pre, cur);
		}
		return pre[m - 1];
	}
};

//只需要保存当前列和前一列，通过swap函数实现pre的移动（即上次的cur，上次的pre丢掉）

//# 3
class Solution {
	int uniquePaths(int m, int n) {
		if (m > n) return uniquePaths(n, m);
		vector<int> cur(m, 1);
		for (int j = 1; j < n; j++)
			for (int i = 1; i < m; i++)
				cur[i] += cur[i - 1];
		return cur[m - 1];
	}
};
//只需要保存cur，因为cur就是后一列的pre
