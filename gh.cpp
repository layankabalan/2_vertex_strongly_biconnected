#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj_list;

public:
    Graph(int vertices) {
        V = vertices;
        adj_list.resize(V);
    }

    void add_edge(int u, int v) {
        adj_list[u].push_back(v);
    }

    void dfs_gabow_util(int v, vector<bool>& visited, vector<bool>& on_stack, stack<int>& pre_order) {
        visited[v] = true;
        on_stack[v] = true;
        pre_order.push(v);

        for (int neighbor : adj_list[v]) {
            if (!visited[neighbor]) {
                dfs_gabow_util(neighbor, visited, on_stack, pre_order);
            } else if (on_stack[neighbor]) {
                while (pre_order.top() != neighbor) {
                    pre_order.push(pre_order.top());
                    pre_order.pop();
                }
                pre_order.push(pre_order.top());
                pre_order.pop();
            }
        }

        on_stack[v] = false;
    }

    vector<int> dfs_gabow() {
        vector<bool> visited(V, false);
        vector<bool> on_stack(V, false);
        stack<int> pre_order;

        for (int v = 0; v < V; v++) {
            if (!visited[v]) {
                dfs_gabow_util(v, visited, on_stack, pre_order);
            }
        }

        vector<int> result;
        while (!pre_order.empty()) {
            result.push_back(pre_order.top());
            pre_order.pop();
        }

        return result;
    }
};

int main() {
    Graph g();
    g.add_edge(, );
    g.add_edge(, );
    g.add_edge(, );
    g.add_edge(, );
    g.add_edge(, );
    g.add_edge(, );
    g.add_edge(, );

    cout << "DFS Gabow Order:" << endl;
    vector<int> order = g.dfs_gabow();
    for (int vertex : order) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}