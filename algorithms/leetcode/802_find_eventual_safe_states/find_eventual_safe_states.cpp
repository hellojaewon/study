#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

bool dfs (int n, vector<vector<int>>& graph, vector<int>& m) {
    if (m[n] == 0) return false;

    if (m[n] == 1)
        return true;

    m[n] = 0;
    auto & nodes = graph[n];
    for (int i = 0; i < nodes.size(); i++) {
        if (!dfs(nodes[i], graph, m))
            return false;
    }
    m[n] = 1;
    return true;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int> m(graph.size(), -1);
    vector<int> result;
    for (int i = 0; i < graph.size(); i++) {
        if (dfs(i, graph, m))
            result.push_back(i);
    }
    return result;
}

void test1() {
    vector<vector<int>> g;
    g.push_back(vector<int>{1,2});
    g.push_back(vector<int>{2,3});
    g.push_back(vector<int>{5});
    g.push_back(vector<int>{0});
    g.push_back(vector<int>{5});
    g.push_back(vector<int>{});
    g.push_back(vector<int>{});
    auto result = eventualSafeNodes(g);
    assert(result.size() == 4);
    assert(result[0] == 2);
    assert(result[1] == 4);
    assert(result[2] == 5);
    assert(result[3] == 6);
}

void test2() {
    vector<vector<int>> g;
    g.push_back(vector<int>{});
    g.push_back(vector<int>{0,2,3,4});
    g.push_back(vector<int>{3});
    g.push_back(vector<int>{4});
    g.push_back(vector<int>{});
    auto result = eventualSafeNodes(g);
    assert(result.size() == 5);
    assert(result[0] == 0);
    assert(result[1] == 1);
    assert(result[2] == 2);
    assert(result[3] == 3);
    assert(result[4] == 4);
}

int main () {
    test1();
    test2();
    return 0;
}
