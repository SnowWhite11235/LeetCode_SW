/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
		// 对每一行，如果这一行的第一列中有0，则将col0置为0
		// 对每一行中的每一列如果有位置为0，则将这行这列的起始位置都置为0
		for (int i = 0; i < rows; i++) {
			if (matrix[i][0] == 0) col0 = 0;
			for (int j = 1; j < cols; j++)
				if (matrix[i][j] == 0)
					matrix[i][0] = matrix[0][j] = 0;
		}
		// 如果某一位置的行或者列起始位置为0，该位置置为0
		// 如果col0为0，则将第一列全部置0
		for (int i = rows - 1; i >= 0; i--) {
			for (int j = cols - 1; j >= 1; j--)
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
			if (col0 == 0) matrix[i][0] = 0;
		}
	}
};

/*
相当于只用了一个存储单元，来“记忆”第一列的情况，然后最后处理第一列；
如果不存这个，就无从得知第一列原本有否0, 因为每一列后面的数会改变第一列的值

十分巧妙
*/