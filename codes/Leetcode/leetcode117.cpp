/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
	public:
		void connect(TreeLinkNode *root) {
			if (root == NULL) return;

			queue<TreeLinkNode*> que;
			que.push(root);

			while (!que.empty()) {
				int n = que.size();
				TreeLinkNode* head = que.front();
				que.pop();

				if (head->left != NULL) que.push(head->left);
				if (head->right != NULL) que.push(head->right);

				for (int i = 1; i < n; i++) {
					TreeLinkNode* next = que.front();
					que.pop();
					head->next = next;
					head = next;

					if (head->left != NULL) que.push(head->left);
					if (head->right != NULL) que.push(head->right);
				}
			}
		}
};
