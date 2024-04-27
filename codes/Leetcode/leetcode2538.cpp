class Solution {
public:

    long long process_cost_down(int u, int from,
        const std::vector<std::vector<int> >& graph,
        const std::vector<int>& prices,
        std::vector<long long>& costs) {
        
        long long& ret = costs[u];
        ret = 0;
        for (int i = 0; i < graph[u].size(); ++i) {
            if (from == graph[u][i]) continue;
            ret = std::max(ret, process_cost_down(graph[u][i], u, graph, prices, costs));
        }
        ret += prices[u];
        return ret;
    } 

    long long process_cost_up(int u, int from,
        const std::vector<std::vector<int> >& graph,
        const std::vector<int>& prices,
        long long upcost,
        std::vector<long long>& costs) {

        long long first_cost = upcost;
        long long second_cost = upcost;
        int first_index = from;
        int second_index = from;
        for (int i = 0; i < graph[u].size(); ++i) {
            if (graph[u][i] == from) continue;
            if (costs[graph[u][i]] > second_cost) {
                second_cost = costs[graph[u][i]];
                second_index = graph[u][i];
            }
            if (second_cost > first_cost) {
                std::swap(first_cost, second_cost);
                std::swap(first_index, second_index);
            }
        }
        
        long long ans = std::max(upcost, costs[u] - prices[u]);
        for (int i = 0; i < graph[u].size(); ++i) {
            if (from == graph[u][i]) continue;
            long long max_cost = (graph[u][i] == first_index ? second_cost : first_cost) + prices[u];
            ans = std::max(ans, process_cost_up(graph[u][i], u, graph, prices, max_cost, costs));
        }
        return ans;
    }

    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        
        // init
        std::vector<std::vector<int> > graph;
        graph.resize(n);

        // build graph
        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].emplace_back(edges[i][1]);
            graph[edges[i][1]].emplace_back(edges[i][0]);
        }

        std::vector<long long> costs;
        costs.resize(n);
        process_cost_down(0, 0, graph, price, costs);
        return process_cost_up(0, 0, graph, price, 0, costs); 
    }
};
