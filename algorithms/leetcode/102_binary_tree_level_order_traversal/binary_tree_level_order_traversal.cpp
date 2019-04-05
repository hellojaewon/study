#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void solve (vector<vector<int>> & result, queue<TreeNode*> q) {
    if (q.empty()) return;
    vector<int> res;
    queue<TreeNode*> nextQ;
    while (!q.empty()) {
        TreeNode * node = q.front();
        q.pop();
        res.push_back(node->val);
        if (node->left) nextQ.push(node->left);
        if (node->right) nextQ.push(node->right);
    }
    result.push_back(res);
    solve(result, nextQ);
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root) {
        queue<TreeNode*> q;
        q.push(root);
        solve(result, q);
    }
    return result;
}

int main () {
//        3
//       / \
//      9  20
//        /  \
//       15   7
    TreeNode n3(3);
    TreeNode n9(9);
    TreeNode n20(20);
    TreeNode n15(15);
    TreeNode n7(7);
    n3.left = &n9;
    n3.right = &n20;
    n20.left = &n15;
    n20.right = &n7;
    auto result = levelOrder(&n3);
//    [
//      [3],
//      [9,20],
//      [15,7]
//    ]

    assert(result.size() == 3);
    assert(result[0].size() == 1);
    assert(result[0][0] == 3);
    assert(result[1].size() == 2);
    assert(result[1][0] == 9);
    assert(result[1][1] == 20);
    assert(result[2].size() == 2);
    assert(result[2][0] == 15);
    assert(result[2][1] == 7);
    return 0;
}
