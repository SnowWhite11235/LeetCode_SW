/*
Given n non - negative integers a1, a2, ..., an, where each represents a point at coordinate(i, ai).
n vertical lines are drawn such that the two endpoints of line i is at(i, ai) and(i, 0).
Find two lines, which together with x - axis forms a container, such that the container contains 
the most water.

Note: You may not slant the container and n is at least 2.
*/

class Solution {
public:
	int maxArea(vector<int>& height) {
		int maxCurr = 0;
		int low = 0, high = height.size() - 1;

		while (low < high){
			int h = min(height[low], height[high]);
			maxCurr = max(maxCurr, h * (high - low));

			while (height[low] <= h) low++;
			while (height[high] <= h) high--;
		}
		return maxCurr;
	}
};

/*
#1 (������) n^2
#2 n
�����Ŀ�ʼ���ҵ�����������ߵ�������
ע������while��ʹ�ã�ֻ��ע��������������Ը���h�ߵ�λ��
*/