#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

char intToChar (int i) {
    return 'a' + i;
}

void solve (TreeNode* root, string chosen, string & smallest) {
    if (!root)
        return;

    chosen.insert(0, 1, intToChar(root->val));
    solve(root->left, chosen, smallest);
    solve(root->right, chosen, smallest);
    if (!root->left && !root->right && (smallest.empty() || chosen < smallest))
        smallest = chosen;
    chosen.erase(0, 1);
}

string smallestFromLeaf(TreeNode* root) {
    string chosen = "";
    string smallest = "";
    solve(root, chosen, smallest);
    return smallest;
}

int main () {
    TreeNode t1_0{0};
    TreeNode t1_1{1};
    TreeNode t1_2{2};
    TreeNode t1_3{3};
    TreeNode t1_4{4};
    TreeNode t1_5{3};
    TreeNode t1_6{4};
    t1_0.left = &t1_1;
    t1_0.right = &t1_2;
    t1_1.left = &t1_3;
    t1_1.right = &t1_4;
    t1_2.left = &t1_5;
    t1_2.right = &t1_6;
    assert(smallestFromLeaf(&t1_0) == "dba");

    TreeNode t2_0{25};
    TreeNode t2_1{1};
    TreeNode t2_2{3};
    TreeNode t2_3{1};
    TreeNode t2_4{3};
    TreeNode t2_5{0};
    TreeNode t2_6{2};
    t2_0.left = &t2_1;
    t2_0.right = &t2_2;
    t2_1.left = &t2_3;
    t2_1.right = &t2_4;
    t2_2.left = &t2_5;
    t2_2.right = &t2_6;
    assert(smallestFromLeaf(&t2_0) == "adz");

    TreeNode t3_0{2};
    TreeNode t3_1{2};
    TreeNode t3_2{1};
    TreeNode t3_4{1};
    TreeNode t3_5{0};
    TreeNode t3_9{0};
    t3_0.left = &t3_1;
    t3_0.right = &t3_2;
    t3_1.right = &t3_4;
    t3_2.left = &t3_5;
    t3_4.left = &t3_9;
    assert(smallestFromLeaf(&t3_0) == "abc");

    TreeNode t4_0{0};
    TreeNode t4_2{1};
    t4_0.right = &t4_2;
    assert(smallestFromLeaf(&t4_0) == "ba");

    return 0;
}
