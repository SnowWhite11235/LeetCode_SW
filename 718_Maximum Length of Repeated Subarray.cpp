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
		int m = A.size(), n = B.size(); //.size()�ǳ�Ա���� �ǵü�����
		if (!m || !n) return 0;			//�Դ���Ĳ���һ��Ҫ�ǵ���֤�Ƿ���Ч
		vector<int> dp(n + 1);          //ע�����ﳤ����n+1ȷ��B���һ��Ԫ�ز�Խ��
		int res = 0;
		for (int i = m - 1; i >= 0; i--){
			for (int j = 0; j<n; j++){
				//����:dp�ĸ��¸�ֵ�ͱ������ֵд��һ����
				res = max(res, dp[j] = A[i] == B[j] ? dp[j + 1] + 1 : 0);
			}
		}
		return res;
	}
};


/*
*1st: (������)n^3 1
*2nd: n^2 n
* A�Ӷ�β��ʼ��B�Ӷ�ͷ�����ж�B�ĵ�ǰԪ���Ƿ���ڵ�ǰA��Ԫ�أ�
* �����������ۼ�B�е�ǰj��j+1��ǰƥ�������ĺͼ�¼��j�У�
* ��res����������������������г��ȣ�
* dp[n]�����B������A��ǰ����ƥ������г��ȣ�һ����ƥ������㡣
* �����뷨��ʵ�Ǳȹ��ľͲ����ٱȽ��ˣ�ֻ��Ҫ��¼��Ŀ�Ϳ��ԣ�
* Ϊʲôj�Ǵ�ǰ����ȣ���Ϊ����ʱҪ�õ���һ��Ԫ�ص�ƥ��������������ͬһ�����ȸı䡣
*/


//�������������飬ע���﷨���������˴����������֤
public int findLength(int[] A, int[] B) {
	int n = A.length, m = B.length, max = 0;
	int[] dp = new int[m + 1]; //***
	for (int i = 1; i <= n; i++)
		for (int j = m; j > 0; j--)
			max = Math.max(max, dp[j] = A[i - 1] == B[j - 1] ? dp[j - 1] + 1 : 0);
	return max;
}