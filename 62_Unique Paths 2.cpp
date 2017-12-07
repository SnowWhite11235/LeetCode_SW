/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
[0,0,0],
[0,1,0],
[0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/


class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		bool isObs = false;
		// 初始化
		vector<int> cur(m, 1);
		for (int i = 0; i < m; i++){
			if (1 == obstacleGrid[i][0]){
				while (i < m){
					cur[i] = 0;
					++i;
				}
			}
		}

		for (int j = 1; j < n; j++){
			if (1 == obstacleGrid[0][j]) isObs = true;
			if (isObs) cur[0] = 0;
			for (int i = 1; i < m; i++){
				if (1 == obstacleGrid[i][j])
					cur[i] = 0;
				else
					cur[i] += cur[i - 1];
			}
		}
		return cur[m - 1];
	}
};

/*
只需要将障碍位置的pathNum清零即可正确计算，但要注意初始化的时候要把第一行和第一列正确清零(只要中间有一个obs 则这一行或一列后边都无法到达)
*/