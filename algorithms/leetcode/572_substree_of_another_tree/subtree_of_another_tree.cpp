#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool solve (TreeNode * s, TreeNode * t) {
    if (s == nullptr && t == nullptr) return true;
    if ((s && t == nullptr) || (s == nullptr && t)) return false;
    if (s->val != t->val) return false;

    assert(s != nullptr);
    assert(t != nullptr);
    if (solve(s->left, t->left) && solve(s->right, t->right))
        return true;
    return false;
}

bool isSubtree(TreeNode* s, TreeNode* t) {
    if (!t) return false;

    queue<TreeNode*> q;
    q.push(s);
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        if (!front) continue;
        if (solve(front, t))
            return true;
        q.push(front->left);
        q.push(front->right);
    }
    return false;
}

void Test1 () {
    TreeNode s3{3};
    TreeNode s4{4};
    TreeNode s5{5};
    TreeNode s1{1};
    TreeNode s2{2};
    s3.left = &s4;
    s3.right = &s5;
    s4.left = &s1;
    s4.right = &s2;

    TreeNode t4{4};
    TreeNode t1{1};
    TreeNode t2{2};
    t4.left = &t1;
    t4.right = &t2;

    assert(isSubtree(&s3, &t4));
}

void Test2 () {
    TreeNode s3{3};
    TreeNode s4{4};
    TreeNode s5{5};
    TreeNode s1{1};
    TreeNode s2{2};
    TreeNode s0{0};
    s3.left = &s4;
    s3.right = &s5;
    s4.left = &s1;
    s4.right = &s2;
    s2.left = &s0;

    TreeNode t4{4};
    TreeNode t1{1};
    TreeNode t2{2};
    t4.left = &t1;
    t4.right = &t2;

    assert(!isSubtree(&s3, &t4));
}

int main () {
    Test1();
    Test2();
    return 0;
}
