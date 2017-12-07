/*
Given a non - negative integer, you could swap two digits at most once to get the maximum valued number.
Return the maximum valued number you could get.

Example 1:
	Input : 2736
	Output : 7236
	 Explanation : Swap the number 2 and the number 7.
Example 2 :
	Input : 9973
	Output : 9973
	Explanation : No swap.
Note :
	The given number is in the range[0, 10^8]

*/

class Solution {
public:
	int maximumSwap(int num) {
		string s_num = to_string(num);
		int n = s_num.length();
		vector<int> dpPosition(n, -1);

		int currMaxPos = n - 1;
		for (int i = n - 1; i >= 0; i--){ 
			//后向前,标记目前为止最大值出现在哪里
			if (s_num[i]>s_num[currMaxPos]) currMaxPos = i;
			dpPosition[i] = currMaxPos;
		}

		for (int i = 0; i<n; i++){
			//前向后，如果最大值不等于当前位置的值，交换最大值和当前位置的值
			if (s_num[dpPosition[i]] != s_num[i]){
				swap(s_num[dpPosition[i]], s_num[i]);
				break;
			}
		}
		return stoi(s_num);
	}
};

/*
将第一个不是按照由大到小顺序排列的数字换到它应该在的位置
#1 (暴力) n^2 1
#2 n n
	后向前标记: 针对每个位置，找到其后所有位置中最大值出现的地方（理想情况是它本身）
	前向后检查: 找到第一个最大值不出现在本身的位置，与它的最大值调换
*/