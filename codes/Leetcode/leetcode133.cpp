/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
	public:
		UndirectedGraphNode* getNode(int label, map<int, UndirectedGraphNode*>& graph) {
			if (graph.find(label) == graph.end()) {
				UndirectedGraphNode* tmp = new UndirectedGraphNode(label);
				graph[label] = tmp;
			}
			return graph[label];
		}

		UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
			if (node == NULL) return NULL;
			set<int> visit;
			map<int, UndirectedGraphNode*> graph;

			queue<UndirectedGraphNode*> que;
			que.push(node);
			visit.insert(node->label);

			while (!que.empty()) {
				UndirectedGraphNode* oldNode = que.front();
				que.pop();

				UndirectedGraphNode* newNode = getNode(oldNode->label, graph);
				for (int i = 0; i < oldNode->neighbors.size(); i++) {
					UndirectedGraphNode* tmp = oldNode->neighbors[i];
					newNode->neighbors.push_back(getNode(tmp->label, graph));

					if (visit.count(tmp->label)) continue;
					visit.insert(tmp->label);
					que.push(tmp);
				}
			}
			return graph[node->label];
		}
};
