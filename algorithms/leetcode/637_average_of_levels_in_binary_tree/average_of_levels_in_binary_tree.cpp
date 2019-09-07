#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<double> averageOfLevels(TreeNode* root) {
    vector<double> result;

    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);
    queue<TreeNode*> next;
    double sum = 0.0;
    int count = 0;
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        sum += front->val;
        count++;
        if (front->left) next.push(front->left);
        if (front->right) next.push(front->right);
        if (q.empty()) {
            q = next;
            next = queue<TreeNode*>{};
            result.push_back(sum / count);
            sum = 0.0;
            count = 0;
        }
    }

    return result;
}

//    3
//   / \
//  9  20
//    /  \
//   15   7
//Output: [3, 14.5, 11]

void Test1 () {
    TreeNode t3{3};
    TreeNode t9{9};
    TreeNode t20{20};
    TreeNode t15{15};
    TreeNode t7{7};

    t3.left = &t9;
    t3.right = &t20;
    t20.left = &t15;
    t20.right = &t7;
    auto res = averageOfLevels(&t3);
    for (auto r : res)
        cout<<r<<endl;
}

int main () {
    Test1();
    return 0;
}
