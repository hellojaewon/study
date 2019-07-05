#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder (TreeNode * root, vector<int> & v) {
    if (!root)
        return;

    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}

int kthSmallest(TreeNode* root, int k) {
    vector<int> v;
    inorder(root, v);
    return v[k-1];
}

void Test1 () {
    TreeNode n3{3};
    TreeNode n1{1};
    TreeNode n4{4};
    TreeNode n2{2};
    n3.left = &n1;
    n3.right = &n4;
    n1.right = &n2;
    assert(kthSmallest(&n3, 1) == 1);
}

void Test2 () {
    TreeNode n5{5};
    TreeNode n3{3};
    TreeNode n6{6};
    TreeNode n2{2};
    TreeNode n4{4};
    TreeNode n1{1};
    n5.left = &n3;
    n5.right = &n6;
    n3.left = &n2;
    n3.right = &n4;
    n2.left = &n1;
    assert(kthSmallest(&n5, 3) == 3);
}

int main () {
    Test1();
    Test2();
    return 0;
}
