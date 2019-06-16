#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (k == 0 || head == NULL)
        return head;
    
    int size = 0;
    ListNode * prev = NULL;
    ListNode * cur = head;
    while (cur != NULL) {
        size++;
        prev = cur;
        cur = cur->next;
    }
    prev->next = head;

    k = k % size;
    size = size - k;
    prev = NULL;
    cur = head; 
    while (size--) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    return cur;
}

int main () {
    ListNode n1{1};
    ListNode n2{2};
    ListNode n3{3};
    ListNode n4{4};
    ListNode n5{5};
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    auto newHead = rotateRight(&n1, 2);
    assert(newHead->val == 4);
    assert(newHead->next->val == 5);
    assert(newHead->next->next->val == 1);
    assert(newHead->next->next->next->val == 2);
    assert(newHead->next->next->next->next->val == 3);
    assert(newHead->next->next->next->next->next == NULL);

    newHead = rotateRight(NULL, 0);
    assert(newHead == NULL);
    newHead = rotateRight(NULL, 10);
    assert(newHead == NULL);
    return 0;
}
