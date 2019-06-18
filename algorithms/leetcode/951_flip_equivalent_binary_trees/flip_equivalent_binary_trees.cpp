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

bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    if ((root1 && !root2) || (!root1 && root2))
        return false;

    if (!root1 && !root2)
        return true;

    if (root1->val != root2->val)
        return false;

    if (   flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)
        || flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)
    )
        return true;

    return false;
}

int main () {
    TreeNode t1_1{1};
    TreeNode t1_2{2};
    TreeNode t1_3{3};
    TreeNode t1_4{4};
    TreeNode t1_5{5};
    TreeNode t1_6{6};
    TreeNode t1_7{7};
    TreeNode t1_8{8};
    t1_1.left = &t1_2;
    t1_1.right = &t1_3;
    t1_2.left = &t1_4;
    t1_2.right = &t1_5;
    t1_3.left = &t1_6;
    t1_5.left = &t1_7;
    t1_5.right = &t1_8;

    TreeNode t2_1{1};
    TreeNode t2_3{3};
    TreeNode t2_2{2};
    TreeNode t2_6{6};
    TreeNode t2_4{4};
    TreeNode t2_5{5};
    TreeNode t2_8{8};
    TreeNode t2_7{7};
    t2_1.left = &t2_3;
    t2_1.right = &t2_2;
    t2_3.right = &t2_6;
    t2_2.left = &t2_4;
    t2_2.right = &t2_5;
    t2_5.left = &t2_8;
    t2_5.right = &t2_7;

    assert(flipEquiv(&t1_1, &t2_1));
    return 0;
}
