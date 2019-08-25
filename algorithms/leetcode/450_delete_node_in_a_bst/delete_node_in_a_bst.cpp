#include <iostream>
#include <algorithm>
#include <queue>
#include <cassert>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode * findNode (TreeNode * root, int key) {
    if (!root) return nullptr;
    if (root->val > key) return findNode(root->left, key);
    if (root->val < key) return findNode(root->right, key);
    return root;
}

TreeNode * findParent (TreeNode * root, TreeNode * key) {
    if (root->left == key || root->right == key)
        return root;
    if (root->val > key->val) return findParent(root->left, key);
    if (root->val < key->val) return findParent(root->right, key);
    return root;
}

TreeNode * findMaximum (TreeNode * parent, TreeNode * root, bool first = false) {
    if (!root->right) {
        if (first)
            parent->right = nullptr;
        else
            parent->right = root->left;
        return root;
    }
    return findMaximum(root, root->right);
}

TreeNode * findMinimum (TreeNode * parent, TreeNode * root, bool first = false) {
    if (!root->left) {
        if (first)
            parent->left = nullptr;
        else
            parent->left = root->right;
        return root;
    }
    return findMinimum(root, root->left);
}

TreeNode * deleteNode(TreeNode* root, int key) {
    TreeNode * found = findNode(root, key);
    if (!found) return root;

    TreeNode * parent = findParent(root, found);
    assert(parent);

    TreeNode * newChild = nullptr;
    if (found->left) {
        TreeNode * tmp = found->right;
        newChild = findMaximum(found, found->left, true);
        if (found->left != newChild)
            newChild->left = found->left;
        newChild->right = tmp;
    } else if (found->right) {
        TreeNode * tmp = found->left;
        newChild = findMinimum(found, found->right, true);
        newChild->left = tmp;
        if (found->right != newChild)
            newChild->right = found->right;
    }

    if (parent->right == found)
        parent->right = newChild;
    else if (parent->left == found)
        parent->left = newChild;
    else if (root == found) {
        if (found->left && found->left != newChild)
            newChild->left = root->left;
        else if (found->right && found->right != newChild)
            newChild->right = root->right;
        root = newChild;
    }

    return root;
}

void PrintBFS (TreeNode * root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto elem = q.front();
        q.pop();
        if (elem->left) q.push(elem->left);
        if (elem->right) q.push(elem->right);
        cout<<elem->val<<endl;
    }
}

//              5
//            3   6
//          2  4 n  7
//
//              5
//            2   6
//          n  4 n  7

void Test1 () {
    TreeNode t5{5};
    TreeNode t3{3};
    TreeNode t6{6};
    TreeNode t2{2};
    TreeNode t4{4};
    TreeNode t7{7};
    t5.left = &t3;
    t5.right = &t6;
    t3.left = &t2;
    t3.right = &t4;
    t6.right = &t7;
    TreeNode * result = deleteNode(&t5, 3);
    PrintBFS(result);
}

void Test2 () {
    TreeNode * result = deleteNode(nullptr, 0);
    assert(result == nullptr);
    PrintBFS(result);
}

void Test3 () {
    TreeNode t0{0};
    TreeNode * result = deleteNode(&t0, 0);
    assert(result == nullptr);
    PrintBFS(result);
}


//
//    3
//  1    4
// n  2
//
//
//    2
//  1   4
void Test4 () {
    TreeNode t3{3};
    TreeNode t1{1};
    TreeNode t4{4};
    TreeNode t2{2};
    t3.left = &t1;
    t3.right = &t4;
    t1.right = &t2;
    TreeNode * result = deleteNode(&t3, 3);
    PrintBFS(result);
}

//          5
//      3       6
//    2  4          7
//
//          5
//      2       6
//       4          7

void Test5 () {
    TreeNode t5{5};
    TreeNode t3{3};
    TreeNode t6{6};
    TreeNode t2{2};
    TreeNode t4{4};
    TreeNode t7{7};
    t5.left = &t3;
    t5.right = &t6;
    t3.left = &t2;
    t3.right = &t4;
    t6.right = &t7;
    TreeNode * result = deleteNode(&t5, 3);
    PrintBFS(result);
}

//        1
//      n   2
//
//
//        2
void Test6 () {
    TreeNode t1{1};
    TreeNode t2{2};
    t1.right = &t2;
    TreeNode * result = deleteNode(&t1, 1);
    PrintBFS(result);
}

//          1
//        n   2
//
//
//
//          1
void Test7 () {
    TreeNode t1{1};
    TreeNode t2{2};
    t1.right = &t2;
    TreeNode * result = deleteNode(&t1, 2);
    PrintBFS(result);
}

//               5
//            3     6
//          1  4   n  n
//        n  2
//
//               5
//            2     6
//          1  4   n  n
void Test8 () {
    TreeNode t5{5};
    TreeNode t3{3};
    TreeNode t6{6};
    TreeNode t1{1};
    TreeNode t4{4};
    TreeNode t2{2};
    t5.left = &t3;
    t5.right = &t6;
    t3.left = &t1;
    t3.right = &t4;
    t1.right = &t2;
    TreeNode * result = deleteNode(&t5, 3);
    PrintBFS(result);
}


//               15
//            3     26
//          1  4   18  57
//        n  2  7   14 20
//                9

void Test9 () {
    TreeNode t15{15};
    TreeNode t3{3};
    TreeNode t26{26};
    TreeNode t1{1};
    TreeNode t4{4};
    TreeNode t2{2};
    TreeNode t57{57};
    TreeNode t18{18};
    TreeNode t14{14};
    TreeNode t20{20};
    TreeNode t7{7};
    TreeNode t9{9};
    t15.left = &t3;
    t15.right = &t26;
    t3.left = &t1;
    t3.right = &t4;
    t1.right = &t2;
    t26.left = &t18;
    t26.right = &t57;
    t18.left = &t14;
    t18.right = &t20;
    t4.right = &t7;
    t7.right = &t9;
    TreeNode * result = deleteNode(&t15, 15);
    PrintBFS(result);
}
void Test10 () {
    TreeNode t0{0};
    TreeNode t1{1};
    TreeNode t2{2};
    TreeNode t3{3};
    TreeNode t4{4};
    TreeNode t5{5};
    TreeNode t6{6};
    TreeNode t7{7};
    TreeNode t8{8};
    TreeNode t9{9};
    TreeNode t10{10};
    TreeNode t11{11};
    TreeNode t12{12};
    TreeNode t13{13};
    TreeNode t14{14};
    TreeNode t15{15};
    TreeNode t16{16};
    TreeNode t17{17};
    TreeNode t18{18};
    TreeNode t19{19};
    TreeNode t20{20};
    TreeNode t21{21};
    TreeNode t22{22};
    TreeNode t23{23};
    TreeNode t24{24};
    TreeNode t25{25};
    TreeNode t26{26};
    TreeNode t27{27};
    TreeNode t28{28};
    TreeNode t29{29};
    TreeNode t30{30};
    TreeNode t31{31};
    TreeNode t32{32};
    TreeNode t33{33};
    TreeNode t34{34};
    TreeNode t35{35};
    TreeNode t36{36};
    TreeNode t37{37};
    TreeNode t38{38};
    TreeNode t39{39};
    TreeNode t40{40};
    TreeNode t41{41};
    TreeNode t42{42};
    TreeNode t43{43};
    TreeNode t44{44};
    TreeNode t45{45};
    TreeNode t46{46};
    TreeNode t47{47};
    TreeNode t48{48};
    TreeNode t49{49};

    t8.left = &t0;
    t8.right = &t31;
    t0.right = &t6;
    t31.left = &t28;
    t31.right = &t45;
    t6.left = &t1;
    t6.right = &t7;
    t28.left = &t25;
    t28.right = &t30;
    t45.left = &t32;
    t45.right = &t49;
    t1.right = &t4;
    t25.left = &t9;
    t25.right = &t26;
    t30.left = &t29;
    t32.right = &t42;
    t49.left = &t47;
    t4.left = &t2;
    t4.right = &t5;
    t9.right = &t12;
    t26.right = &t27;
    t42.left = &t41;
    t42.right = &t43;
    t47.left = &t46;
    t47.right = &t48;
    t2.right = &t3;
    t12.left = &t10;
    t12.right = &t19;
    TreeNode * result = deleteNode(&t8, 1);
    PrintBFS(result);
}

void Test11 () {
    TreeNode t3{3};
    TreeNode t2{2};
    TreeNode t4{4};
    TreeNode t1{1};
    t3.left = &t2;
    t3.right = &t4;
    t2.left = &t1;
    TreeNode * result = deleteNode(&t3, 3);
    PrintBFS(result);
}

int main () {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    Test11();
    return 0;
}
