/*
Given a matrix of m x n elements(m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix :

[
	[1, 2, 3],
	[4, 5, 6],
	[7, 8, 9]
]
You should return[1, 2, 3, 6, 9, 8, 7, 4, 5].
*/


class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<vector<int> > dirs{ { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };//→ ↓ ← ↑
		vector<int> res;
		int nr = matrix.size();     if (nr == 0) return res;
		int nc = matrix[0].size();  if (nc == 0) return res;

		vector<int> nSteps{ nc, nr - 1 }; //列数 行数-1（从0行开始）

		int iDir = 0;           // index of direction
		int ir = 0, ic = -1;    // initial position

		while (nSteps[iDir % 2]){   //列先动
			for (int i = 0; i<nSteps[iDir % 2]; ++i){
				ir += dirs[iDir][0];
				ic += dirs[iDir][1];
				res.push_back(matrix[ir][ic]);
			}
			nSteps[iDir % 2]--; //走了一个方向 r/c要-1
			iDir = (iDir + 1) % 4;
		}
		return res;
	}
};

/*
找到规律：上下左右方向的变换次数与矩阵行列的数目相关

注意这三个变量的使用~
iDir是 0 1 2 3循环的，
一方面作为dirs的索引，作为行列改变的依据；
另一方面作为nSteps的索引标志着现在正在进行的是行改变还是列改变，
并辅助改变现存的行列数，只有奇偶有意义 iDir%2 = 0,1,0,1……

记得检验初始状态，ir，ic的初始值是否能将所有元素包含进来。

*/