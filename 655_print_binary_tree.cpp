#include <vector>
#include <string>
using namespace std;


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
struct que1
{
	TreeNode* t;
	int row;
	int col;
};
TreeNode* que[1100];
que1 q[1100];
int head = 0;
int tail = 0;
class Solution {
public:
	vector<vector<string>> printTree(TreeNode* root)
	{
		que[tail++] = root;
		que[tail++] = nullptr;
		int height = 1;
		while (tail != head)
		{
			if (que[head] != nullptr)
			{
				if (que[head]->left != nullptr)
					que[tail++] = que[head]->left;
				if (que[head]->right != nullptr)
					que[tail++] = que[head]->right;
			}
			else if (tail - head == 1)
				break;
			else
			{
				que[tail++] = nullptr;
				height++;
			}
			head++;
		}
		vector<vector<string>>ans(height + 1, vector<string>(pow(2, height + 1) - 1, ""));
		head = 0;
		tail = 0;
		q[tail].t = root;
		q[tail].row = 0;
		q[tail].col = (pow(2, height + 1) - 2) / 2;
		tail++;
		while (tail != head)
		{
			if (q[head].t != nullptr)
			{
				ans[q[head].row][q[head].col] = to_string(q[head].t->val);
				if (q[head].t->left != nullptr)
				{
					q[tail].t = q[head].t->left;
					q[tail].row = q[head].row + 1;
					q[tail].col = q[head].col - pow(2, height - q[head].row - 1);
					tail++;
				}
				if (q[head].t->right != nullptr)
				{
					q[tail].t = q[head].t->right;
					q[tail].row = q[head].row + 1;
					q[tail].col = q[head].col + pow(2, height - q[head].row - 1);
					tail++;
				}
			}
			else if (tail - head == 1)
				break;
			else
				q[tail++].t = nullptr;
			head++;
		}

    }
};