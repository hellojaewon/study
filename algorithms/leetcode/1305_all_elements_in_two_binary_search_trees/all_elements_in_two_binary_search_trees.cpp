#include <iostream>
#include <vector>
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

void inorder (vector<int> & result, TreeNode * root) {
    if (!root)
        return;

    inorder(result, root->left);
    result.push_back(root->val);
    inorder(result, root->right);
}

vector<int> sort (TreeNode* root) {
    vector<int> result;
    inorder(result, root);
    return result;
}

vector<int> merge (vector<int> & v1, vector<int> & v2) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j])
            result.push_back(v1[i++]);
        else if (v1[i] > v2[j])
            result.push_back(v2[j++]);
        else {
            result.push_back(v1[i++]);
            result.push_back(v2[j++]);
        }
    }

    while (i < v1.size())
        result.push_back(v1[i++]);
    while (j < v2.size())
        result.push_back(v2[j++]);

    return result;
}

vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> result;

    auto sort1 = sort(root1);
    auto sort2 = sort(root2);
    result = merge(sort1, sort2);
    return result;
}

void printVector (const vector<int> & v) {
    for (auto x : v)
        cout<<x<<",";
    cout<<endl;
}

void test1 () {
    // Input: root1 = [2,1,4], root2 = [1,0,3]
    // Output: [0,1,1,2,3,4]

    vector<int> answer{0,1,1,2,3,4};

    TreeNode a2{2};
    TreeNode a1{1};
    TreeNode a4{4};

    a2.left = &a1;
    a2.right = &a4;

    TreeNode b1{1};
    TreeNode b0{0};
    TreeNode b3{3};

    b1.left = &b0;
    b1.right = &b3;

    auto result = getAllElements(&a2, &b1);
    printVector(result);
    assert(result == answer);
}

int main () {
    test1();
    return 0;
}
