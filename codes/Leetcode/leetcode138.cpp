/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
	public:
		RandomListNode *copyRandomList(RandomListNode *head) {
			if (head == NULL) return NULL;
			map<int, RandomListNode *> graph;

			RandomListNode* mov = head;
			while (mov != NULL) {
				graph[mov->label] =  new RandomListNode(mov->label);
				mov = mov->next;
			}

			RandomListNode* first = graph[head->label];
			mov = first;

			while (head != NULL) {
				mov->next = (head->next == NULL ? NULL : graph[head->next->label]);
				mov->random = (head->random == NULL ? NULL : graph[head->random->label]);
				mov = mov->next;
				head = head->next;
			}

			return first;
		}
};
