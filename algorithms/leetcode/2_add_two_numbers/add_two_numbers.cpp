#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode * head = nullptr;
    ListNode * tail = nullptr;
    while (l1 || l2 || carry) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = sum >= 10 ? 1 : 0;
        auto node = new ListNode(sum % 10);
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    return head;
}

ListNode * MakeList (vector<int> v) {
    ListNode * head = nullptr;
    ListNode * tail = nullptr;
    for (auto x : v) {
        auto node = new ListNode(x);
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

int main () {
    auto l1 = MakeList(vector<int>{2,4,3});
    auto l2 = MakeList(vector<int>{5,6,4});
    auto result = addTwoNumbers(l1, l2);
    assert(result);
    assert(result->val == 7);
    assert(result->next->val == 0);
    assert(result->next->next->val == 8);

    auto l11 = MakeList(vector<int>{5});
    auto l22 = MakeList(vector<int>{5});
    result = addTwoNumbers(l11, l22);
    assert(result);
    assert(result->val == 0);
    assert(result->next->val == 1);

    auto l111 = MakeList(vector<int>{1});
    auto l222 = MakeList(vector<int>{9, 9});
    result = addTwoNumbers(l111, l222);
    assert(result);
    assert(result->val == 0);
    assert(result->next->val == 0);
    assert(result->next->next->val == 1);

    return 0;
}
