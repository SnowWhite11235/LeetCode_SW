/*Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
Input :
A : [1, 2, 3, 2, 1]
B : [3, 2, 1, 4, 7]
Output : 3
	 Explanation :
				 The repeated subarray with maximum length is[3, 2, 1].
			 Note :
				  1 <= len(A), len(B) <= 1000
				  0 <= A[i], B[i] < 100

				  https://leetcode.com/problems/maximum-length-of-repeated-subarray/solution/
*/

class Solution {
public:
	int findLength(vector<int>& A, vector<int>& B) {
		int m = A.size(), n = B.size(); //.size()是成员函数 记得加括号
		if (!m || !n) return 0;			//对传入的参数一定要记得验证是否有效
		vector<int> dp(n + 1);          //注意这里长度是n+1确保B最后一个元素不越界
		int res = 0;
		for (int i = m - 1; i >= 0; i--){
			for (int j = 0; j<n; j++){
				//核心:dp的更新赋值和保留最大值写在一起了
				res = max(res, dp[j] = A[i] == B[j] ? dp[j + 1] + 1 : 0);
			}
		}
		return res;
	}
};


/*
*1st: (暴力解)n^3 1
*2nd: n^2 n
* A从队尾开始，B从队头，先判断B的当前元素是否等于当前A的元素，
* 迭代过程中累加B中当前j与j+1此前匹配数量的和记录在j中，
* 用res保留计算过程中最大的子序列长度，
* dp[n]则代表B中能与A当前序列匹配的序列长度，一旦不匹配则归零。
* 本质想法其实是比过的就不用再比较了，只需要记录数目就可以；
* 为什么j是从前往后比？因为计算时要用到后一个元素的匹配数量，不能在同一轮中先改变。
*/


//如果传入的是数组，注意语法；这里少了传入参数的验证
public int findLength(int[] A, int[] B) {
	int n = A.length, m = B.length, max = 0;
	int[] dp = new int[m + 1]; //***
	for (int i = 1; i <= n; i++)
		for (int j = m; j > 0; j--)
			max = Math.max(max, dp[j] = A[i - 1] == B[j - 1] ? dp[j - 1] + 1 : 0);
	return max;
}