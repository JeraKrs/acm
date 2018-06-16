/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	public:
		vector<TreeNode*> generateTree(int start, int end) {
			vector<TreeNode*> ret;
			if (start > end) {
				ret.push_back(0);
				return ret;
			}

			for (int i = start; i <= end; i++) {
				vector<TreeNode*> l = generateTree(start, i-1);
				vector<TreeNode*> r = generateTree(i+1, end);

				for (int x = 0; x < l.size(); x++) {
					for (int y = 0; y < r.size(); y++) {
						TreeNode* c = new TreeNode(i);
						c->left = l[x];
						c->right = r[y];
						ret.push_back(c);
					}
				}
			}
			return ret;
		}

		vector<TreeNode*> generateTrees(int n) {
			if (n == 0) return {};
			return generateTree(1, n);
		}
};
