#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if (head == nullptr)
        return false;

    ListNode * fast = head->next;
    ListNode * slow = head;
    while (fast != nullptr && fast->next != nullptr && slow != nullptr) {
        if (fast == slow)
            return true;
        fast = fast->next->next;
        slow = slow->next;
    }
    return false;
}

void test1 () {
    ListNode n0{3};
    ListNode n1{2};
    ListNode n2{0};
    ListNode n3{-4};
    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n1;
    assert(hasCycle(&n0) == true);
}

void test2 () {
    ListNode n0{1};
    ListNode n1{2};
    n0.next = &n1;
    n1.next = &n0;
    assert(hasCycle(&n0) == true);
}

void test3 () {
    ListNode n0{1};
    assert(hasCycle(&n0) == false);
}

int main () {
    test1();
    test2();
    test3();
    return 0;
}
