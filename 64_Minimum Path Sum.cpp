/*
Given a m x n grid filled with non - negative numbers, find a path from top 
left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

	  Example 1 :
	  [[1, 3, 1],
	  [1, 5, 1],
	  [4, 2, 1]]
Given the above grid map, return 7. Because the path 1��3��1��1��1 minimizes the sum.

*/

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		//cur������ʼ��
		vector<int> cur(m, grid[0][0]); //��ʼ����ֵֻ�Ե�һ��λ����Ч
		for (int i = 1; i < m; ++i){
			cur[i] = cur[i - 1] + grid[i][0];
		}
		//
		for (int i = 1; i < n; ++i){
			cur[0] += grid[0][i]; //�г�ʼ��
			for (int j = 1; j < m; ++j){
				cur[j] = min(cur[j - 1],cur[j]) + grid[j][i];
			}
		}
		return cur[m - 1];
	}

};


/*


*/