#include <iostream>
#include <vector>
#include <cassert>
#include <stack>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<int> preorder(Node* root) {
    vector<int> result;
    stack<Node*> s;

    s.push(root);
    while (!s.empty()) {
        auto top = s.top();
        s.pop();
        if (!top)
            break;
        result.push_back(top->val);
        for (int i = top->children.size() - 1; i >= 0; i--)
            s.push(top->children[i]);
    }
    return result;
}

void test1 () {
//Input: root = [1,null,3,2,4,null,5,6]
//Output: [1,3,5,6,2,4]

    Node n5{5};
    Node n6{6};
    vector<Node*> c2;
    c2.push_back(&n5);
    c2.push_back(&n6);
    Node n3{3, c2};

    Node n2{2};
    Node n4{4};
    vector<Node*> c1;
    c1.push_back(&n3);
    c1.push_back(&n2);
    c1.push_back(&n4);
    Node n1{1, c1};
    auto res = preorder(&n1);
    vector<int> expected{1,3,5,6,2,4};
    assert(res == expected);
}

int main () {
    test1();

    return 0;
}
