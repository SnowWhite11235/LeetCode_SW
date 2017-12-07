/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
[7],
[2, 2, 3]
]

*/

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int> > res;
		vector<int> combination;
		combinationSum(candidates, target, res, combination, 0);
		return res;
	}
private:
	void combinationSum(vector<int> &candidates, int target, vector<vector<int> > &res, vector<int> &combination, int begin){
		if (!target){ //���ҵ�һ�����
			res.push_back(combination);
			return;//ע��˴��Ƿ�����һ���ݹ飬����ֱ�ӷ���������
		}
		//�����￪ʼ��or��
		for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i){ //��ʣ��Ԫ�ػ���targetС���п��ܷ���������ʱ�����
			combination.push_back(candidates[i]); //combination�洢�˵�ǰ���ܵ�һ����ϣ�һ��������Ԫ��push��ȥ
			//�ݹ飬��������������ݹ飬���ϵݹ�
			combinationSum(candidates, target - candidates[i], res, combination, i);//ע�������������Ȼ��i����Ϊ�����ظ�����ÿ��Ԫ��
			combination.pop_back();//�Ѽ������Ԫ��pop��ȥ��Ϊ�˳�����һ�ֿ�����
		}
	}
};



/*
�ݹ飺
ֱ��˼���޷������ʱ�򣬳��԰�����������ɸ���ģ��С���������Ƶ������⡣
�����У�ÿ��ѭ������ʼλ��i��ͬ��ע�Ᵽ��res����ķ�ʽ��û��ʹ�÷���ֵ����Ϊ������֪�����ٲ�ѭ����
ÿһ�����ѡ������һ��λ���ϵ�����
*/