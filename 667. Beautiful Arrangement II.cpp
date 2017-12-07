/*
Given two integers n and k, you need to construct a list which contains n different positive integers 
ranging from 1 to n and obeys the following requirement :
Suppose this list is[a1, a2, a3, ..., an], then the list[| a1 - a2 | , | a2 - a3 | , | a3 - a4 | 
, ..., | an - 1 - an | ] has exactly k distinct integers.

If there are multiple answers, print any of them.

Example 1 :
Input : n = 3, k = 1
Output : [1, 2, 3]
Explanation : The[1, 2, 3] has three different positive integers ranging from 1 to 3, and the[1, 1] 
				has exactly 1 distinct integer : 1.

Example 2 :
Input : n = 3, k = 2
Output : [1, 3, 2]
Explanation : The[1, 3, 2] has three different positive integers ranging from 1 to 3, and the[2, 1] 
				has exactly 2 distinct integers : 1 and 2.

Note :
	The n and k are in the range 1 <= k < n <= 10^4.

*/

class Solution {
public:
	vector<int> constructArray(int n, int k) {
		int l = 1, r = k + 1;
		vector<int> ans;
		while (l <= r) {
			ans.push_back(l++);
			if (l <= r) ans.push_back(r--); //解决了奇偶问题
		}
		for (int i = k + 2; i <= n; i++)
			ans.push_back(i);
		return ans;
	}
};

/*
核心问题：如何构造？容易知道，首尾元素差异最大，往中间次之……
	然而，使用第1个数和第n个数的差开始，乱序与正序衔接的部分可能会引入新的差（可以通过判断奇偶解决）；
	而使用第1个数和第n个数的差开始，衔接部分的差一定在1与k之间（非常理想）
	1, k + 1, 2, k, 3, k - 1 ... ==>  k, k - 1, k - 2, ..., 2, 1 把剩下的补齐

误区：容易将2nd和3rd，4th和5th之间的差漏掉
	前面的每个差不一定只能出现一次
*/