#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int smallestLevelSum(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int currentLevel = 1;
    int max = root->val;
    int smallestLevel = 1;
    while (q.size()) {
        int sum = 0;
        int n = q.size();
        for (int i = 0; i < n; i++) {
            auto node = q.front();
            q.pop();
            sum += node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        if (max < sum) {
            max = sum;
            smallestLevel = currentLevel;
        }
        currentLevel++;
    }
    return smallestLevel;
}

void test1 () {
    // Input: root = [1,7,0,7,-8,null,null]
    // Output: 2
    TreeNode n1{1};
    TreeNode n0{0};
    TreeNode n7_1{7};
    TreeNode n7_2{7};
    TreeNode n8{-8};

    n1.left = &n7_1;
    n1.right = &n0;
    n7_1.left = &n7_2;
    n7_1.right = &n8;

    assert(smallestLevelSum(&n1) == 2);
}

int main () {
    test1();

    return 0;
}
