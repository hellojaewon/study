#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool solve (TreeNode * root, int remaining) {
    remaining -= root->val;
    if (!root->left && !root->right) {
        if (remaining == 0)
            return true;
        return false;
    }
    if (root->left && solve(root->left, remaining))
        return true;
    if (root->right && solve(root->right, remaining))
        return true;
    return false;
}

bool hasPathSum(TreeNode* root, int sum) {
    if (!root)
        return false;

    return solve(root, sum);
}

void Test1() {
    TreeNode t5{5};
    TreeNode t4_1{4};
    TreeNode t8{8};
    TreeNode t11{11};
    TreeNode t13{13};
    TreeNode t4_2{4};
    TreeNode t7{7};
    TreeNode t2{2};
    TreeNode t1{1};
    t5.left = &t4_1;
    t5.right = &t8;
    t4_1.left = &t11;
    t8.left = &t13;
    t8.right = &t4_2;
    t11.left = &t7;
    t11.right = &t2;
    t4_2.right = &t1;
    assert(hasPathSum(&t5, 22));
    assert(hasPathSum(&t5, 18));
    assert(hasPathSum(&t5, 26));
    assert(hasPathSum(&t5, 27));
    assert(!hasPathSum(&t5, 28));
}

void Test2 () {
    assert(!hasPathSum(nullptr, 0));
}

void Test3 () {
    TreeNode t1{1};
    TreeNode t2{2};
    t1.left = &t2;
    assert(!hasPathSum(&t1, 1));
}

int main () {
    Test1();
    Test2();
    Test3();
    return 0;
}
