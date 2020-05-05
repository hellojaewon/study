#include <iostream>
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

int deepestLeavesSum(TreeNode* root) {
    if (!root)
        return 0;

    queue<TreeNode*> q;
    q.push(root);
    int sum = 0;
    while (!q.empty()) {
        int size = q.size();
        sum = 0;
        for (int i = 0; i < size; i++) {
            TreeNode * node = q.front();
            q.pop();
            sum += node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return sum;
}

void Test1 () {
    TreeNode n1{1};
    TreeNode n2{2};
    TreeNode n3{3};
    TreeNode n4{4};
    TreeNode n5{5};
    TreeNode n6{6};
    TreeNode n7{7};
    TreeNode n8{8};

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.right = &n6;
    n4.left = &n7;
    n6.right = &n8;

    assert(deepestLeavesSum(&n1) == 15);
}

int main () {
    Test1();
    return 0;
}
