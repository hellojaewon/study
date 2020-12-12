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

ListNode * swapPairs (ListNode * head) {
    if (!head)
        return head;

    if (!head->next)
        return head;

    auto first = head;
    auto second = head->next;
    first->next = swapPairs(second->next);
    second->next = first;
    return second;
}

void printList (const ListNode * root) {
    while (root) {
        cout<<root->val<<",";
        root = root->next;
    }
    cout<<endl;
}

void test1 () {
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    printList(&n1);
    auto root = swapPairs(&n1);
    printList(root);
}

void test2 () {
    auto root = swapPairs(nullptr);
    printList(root);
}

void test3 () {
    ListNode n1(1);

    printList(&n1);
    auto root = swapPairs(&n1);
    printList(root);
}

int main () {
    test1();
    test2();
    test3();

    return 0;
}
