class Solution {
public:
	int widthOfBinaryTree(TreeNode* root)
	{
		vector<vector<unsigned int>>res;
		queue<pair<TreeNode*, unsigned int>>que;
		que.push({ root ,1 });
		que.push({ nullptr, 0 });
		vector<unsigned int>temp;
		TreeNode* pre = nullptr;
		while (!que.empty())
		{
			pair<TreeNode*, unsigned int>& p = que.front();
			if (p.first == nullptr)
			{
				if (pre == nullptr)
					break;
				if (temp.size() != 0)
				{
					res.push_back(temp);
					temp.clear();
				}
				pre = nullptr;
				que.push({ nullptr, 0 });
				que.pop();
				continue;
			}
			temp.push_back(p.second);
			pre = p.first;
			if (p.first->left != nullptr)
				que.push({ p.first->left ,2 * p.second });
			if (p.first->right != nullptr)
				que.push({ p.first->right ,2 * p.second + 1 });
			que.pop();
		}
		unsigned int row = res.size();
		unsigned int len = 0;
		for (long long i = 0; i < row; ++i)
		{
			if(!res[i].empty())
			len = len > res[i].back() - res[i].front() ? len : res[i].back() - res[i].front();
		}
		return len+1;
	}
};