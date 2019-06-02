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

TreeNode * solve (vector<int> & nums, vector<int>::iterator begin, vector<int>::iterator end) {
    if (begin == end)
        return nullptr;
    auto max = std::max_element(begin, end);
    auto node = new TreeNode(*max);
    node->left = solve(nums, begin, max);
    node->right = solve(nums, max + 1, end);
    return node;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return solve(nums, nums.begin(), nums.end());
};

int main () {
    std::vector<int> nums{3,2,1,6,0,5};
    auto root = constructMaximumBinaryTree(nums);
    assert(root->val == 6);
    assert(root->left->val == 3);
    assert(root->left->right->val == 2);
    assert(root->left->right->right->val == 1);
    assert(root->right->val == 5);
    assert(root->right->left->val == 0);
    return 0;
}
