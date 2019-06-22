#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode * MakeTree (vector<int> & v, int left, int right) {
    if (left > right)
        return nullptr;

    int mid = (left + right) / 2;
    TreeNode * root = new TreeNode(v[mid]);
    root->left = MakeTree(v, left, mid - 1);
    root->right = MakeTree(v, mid + 1, right);
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    vector<int> v;
    while (head) {
        v.push_back(head->val);
        head = head->next;
    }

    return MakeTree(v, 0, v.size() - 1);
}

int main () {
    ListNode n1{-10};
    ListNode n2{-3};
    ListNode n3{0};
    ListNode n4{5};
    ListNode n5{9};
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    sortedListToBST(&n1);
    return 0;
}
