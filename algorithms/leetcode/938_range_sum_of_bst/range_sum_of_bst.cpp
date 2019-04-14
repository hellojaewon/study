#include <iostream>
#include <cstdio>
#include <cassert>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int rangeSumBST(TreeNode* root, int L, int R) {
    if (!root) return 0;
    int left = 0, right = 0, cur = 0;
    if (L < root->val)
        left = rangeSumBST(root->left, L, R);
    if (root->val < R)
        right = rangeSumBST(root->right, L, R);
    if (L <= root->val && root->val <= R)
        cur = root->val;
    return left + cur + right;
}

int main () {
    // Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
    // Output: 32
    TreeNode n10(10);
    TreeNode n5(5);
    TreeNode n15(15);
    TreeNode n3(3);
    TreeNode n7(7);
    TreeNode n18(18);
    n10.left = &n5;
    n10.right = &n15;
    n5.left = &n3;
    n5.right = &n7;
    n15.right = &n18;
    assert(rangeSumBST(&n10, 7, 15) == 32);

    // Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
    // Output: 23
    TreeNode t10(10);
    TreeNode t5(5);
    TreeNode t15(15);
    TreeNode t3(3);
    TreeNode t7(7);
    TreeNode t13(13);
    TreeNode t18(18);
    TreeNode t1(1);
    TreeNode t6(6);
    t10.left = &t5;
    t10.right = &t15;
    t5.left = &t3;
    t5.right = &t7;
    t15.left = &t13;
    t15.right = &t18;
    t3.left = &t1;
    t7.left = &t6;
    assert(rangeSumBST(&t10, 6, 10) == 23);
    return 0;
}
