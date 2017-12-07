/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 
can be used and each combination should be a unique set of numbers.

Example 1:
Input : k = 3, n = 7
Output : [[1, 2, 4]]

Example 2 :
Input : k = 3, n = 9
Output :[[1, 2, 6], [1, 3, 5], [2, 3, 4]]
*/

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int> > res;
		vector<int> combination;
		combinationSum3(n, res, combination, 1, k);
		return res;
	}

private:
	void combinationSum3(int target, vector<vector<int> > &res, vector<int> &combination, int begin, int need){
		if (!target){
			res.push_back(combination);
			return;
		}
		else if (!need)
			return;
		//画图就知道target的约束是什么意思了，长方形加三角形变成一个梯形
		for (int i = begin; i != 10 && target >= i * need + need * (need - 1) / 2; ++i){
			combination.push_back(i);
			combinationSum3(target - i, res, combination, i + 1, need - 1);
			combination.pop_back();
		}
	}
};
