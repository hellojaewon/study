#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void findPath (vector<vector<int>> & graph, int x, vector<int> & path, int target, vector<vector<int>> & result) {
    if (x == target) {
        path.push_back(x);
        result.push_back(path);
        path.pop_back();
        return;
    }

    auto nodes = graph[x];
    path.push_back(x);
    for (auto next : nodes) {
        findPath(graph, next, path, target, result);
    }
    path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> result;

    int target = graph.size() - 1;
    vector<int> path;
    path.push_back(0);
    for (auto x : graph[0])
        findPath(graph, x, path, target, result);

    return result;
}

void printVectorOfVector (const vector<vector<int>> & v) {
    for (auto x : v) {
        cout<<"[";
        for (auto i : x)
            cout<<i<<",";
        cout<<"]"<<endl;
    }
}

void test1 () {
    // Input: graph = [[1,2],[3],[3],[]]
    // Output: [[0,1,3],[0,2,3]]
    //
    vector<vector<int>> graph;
    graph.push_back(vector<int>{1,2});
    graph.push_back(vector<int>{3});
    graph.push_back(vector<int>{3});
    graph.push_back(vector<int>{});

    cout<<"graph1"<<endl;
    printVectorOfVector(graph);
    auto result = allPathsSourceTarget(graph);
    cout<<"result1"<<endl;
    printVectorOfVector(result);
    assert(result.size() == 2);
}

void test2 () {
    // Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
    // Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
    vector<vector<int>> graph;
    graph.push_back(vector<int>{4,3,1});
    graph.push_back(vector<int>{3,2,4});
    graph.push_back(vector<int>{3});
    graph.push_back(vector<int>{4});
    graph.push_back(vector<int>{});

    cout<<"graph2"<<endl;
    printVectorOfVector(graph);
    auto result = allPathsSourceTarget(graph);
    cout<<"result2"<<endl;
    printVectorOfVector(result);
    assert(result.size() == 5);
}

void test3 () {
    // Input: graph = [[1],[]]
    // Output: [[0,1]]
    vector<vector<int>> graph;
    graph.push_back(vector<int>{1});
    graph.push_back(vector<int>{});

    cout<<"graph3"<<endl;
    printVectorOfVector(graph);
    auto result = allPathsSourceTarget(graph);
    cout<<"result3"<<endl;
    printVectorOfVector(result);
    assert(result.size() == 1);
}

void test4 () {
    // Input: graph = [[1,2,3],[2],[3],[]]
    // Output: [[0,1,2,3],[0,2,3],[0,3]]
    vector<vector<int>> graph;
    graph.push_back(vector<int>{1,2,3});
    graph.push_back(vector<int>{2});
    graph.push_back(vector<int>{3});
    graph.push_back(vector<int>{});

    cout<<"graph4"<<endl;
    printVectorOfVector(graph);
    auto result = allPathsSourceTarget(graph);
    cout<<"result4"<<endl;
    printVectorOfVector(result);
    assert(result.size() == 3);
}

void test5 () {
    // Input: graph = [[1,3],[2],[3],[]]
    // Output: [[0,1,2,3],[0,3]]
    vector<vector<int>> graph;
    graph.push_back(vector<int>{1,3});
    graph.push_back(vector<int>{2});
    graph.push_back(vector<int>{3});
    graph.push_back(vector<int>{});

    cout<<"graph5"<<endl;
    printVectorOfVector(graph);
    auto result = allPathsSourceTarget(graph);
    cout<<"result5"<<endl;
    printVectorOfVector(result);
    assert(result.size() == 2);
}

int main () {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}
