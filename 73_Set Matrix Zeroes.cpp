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
		// ��ÿһ�У������һ�еĵ�һ������0����col0��Ϊ0
		// ��ÿһ���е�ÿһ�������λ��Ϊ0�����������е���ʼλ�ö���Ϊ0
		for (int i = 0; i < rows; i++) {
			if (matrix[i][0] == 0) col0 = 0;
			for (int j = 1; j < cols; j++)
				if (matrix[i][j] == 0)
					matrix[i][0] = matrix[0][j] = 0;
		}
		// ���ĳһλ�õ��л�������ʼλ��Ϊ0����λ����Ϊ0
		// ���col0Ϊ0���򽫵�һ��ȫ����0
		for (int i = rows - 1; i >= 0; i--) {
			for (int j = cols - 1; j >= 1; j--)
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
			if (col0 == 0) matrix[i][0] = 0;
		}
	}
};

/*
�൱��ֻ����һ���洢��Ԫ���������䡱��һ�е������Ȼ��������һ�У�
���������������޴ӵ�֪��һ��ԭ���з�0, ��Ϊÿһ�к��������ı��һ�е�ֵ

ʮ������
*/