#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head) {
    if (!head) return;

    ListNode * slow = head;
    ListNode * fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode * second = slow->next;
    slow->next = nullptr;

    ListNode * prev = nullptr;
    while (second) {
        ListNode * tmp = second->next;
        second->next = prev;
        prev = second;
        second = tmp;
    }

    second = prev;
    while (head && second) {
        ListNode * tmp = head->next;
        head->next = second;
        head = tmp;
        tmp = second->next;
        second->next = head;
        second = tmp;
    }
}

void test1 () {
    ListNode l0{1};
    ListNode l1{2};
    ListNode l2{3};
    ListNode l3{4};
    l0.next = &l1;
    l1.next = &l2;
    l2.next = &l3;
    reorderList(&l0);
    vector<int> expected{1,4,2,3};
    auto ptr = &l0;
    for (auto e : expected) {
        assert(e == ptr->val);
        ptr = ptr->next;
    }
}

void test2 () {
    ListNode l0{1};
    ListNode l1{2};
    ListNode l2{3};
    ListNode l3{4};
    ListNode l4{5};
    l0.next = &l1;
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    reorderList(&l0);
    vector<int> expected{1,5,2,4,3};
    auto ptr = &l0;
    for (auto e : expected) {
        assert(e == ptr->val);
        ptr = ptr->next;
    }
}

void test3 () {
    ListNode l0{1};
    ListNode l1{2};
    l0.next = &l1;
    reorderList(&l0);
    vector<int> expected{1,2};
    auto ptr = &l0;
    for (auto e : expected) {
        assert(e == ptr->val);
        ptr = ptr->next;
    }
}

int main () {
    test1();
    test2();
    test3();

    return 0;
}
