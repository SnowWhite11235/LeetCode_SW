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
		if (!target){ //若找到一个组合
			res.push_back(combination);
			return;//注意此处是返回上一个递归，不是直接返回主函数
		}
		//从这里开始看or想
		for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i){ //当剩余元素还比target小，有可能符合条件的时候继续
			combination.push_back(candidates[i]); //combination存储了当前可能的一个组合，一个个把新元素push进去
			//递归，符合条件则继续递归，不断递归
			combinationSum(candidates, target - candidates[i], res, combination, i);//注意这里的条件仍然是i，因为可以重复利用每个元素
			combination.pop_back();//把加入的新元素pop出去，为了尝试下一种可能性
		}
	}
};



/*
递归：
直接思考无法解决的时候，尝试把问题拆解成若干个规模更小，性质类似的子问题。
本题中，每次循环的起始位置i不同，注意保存res结果的方式并没有使用返回值（因为根本不知道多少层循环）
每一层调用选定的是一个位置上的数字
*/