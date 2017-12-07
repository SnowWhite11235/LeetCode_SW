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
			//����ǰ,���ĿǰΪֹ���ֵ����������
			if (s_num[i]>s_num[currMaxPos]) currMaxPos = i;
			dpPosition[i] = currMaxPos;
		}

		for (int i = 0; i<n; i++){
			//ǰ���������ֵ�����ڵ�ǰλ�õ�ֵ���������ֵ�͵�ǰλ�õ�ֵ
			if (s_num[dpPosition[i]] != s_num[i]){
				swap(s_num[dpPosition[i]], s_num[i]);
				break;
			}
		}
		return stoi(s_num);
	}
};

/*
����һ�����ǰ����ɴ�С˳�����е����ֻ�����Ӧ���ڵ�λ��
#1 (����) n^2 1
#2 n n
	����ǰ���: ���ÿ��λ�ã��ҵ��������λ�������ֵ���ֵĵط������������������
	ǰ�����: �ҵ���һ�����ֵ�������ڱ����λ�ã����������ֵ����
*/