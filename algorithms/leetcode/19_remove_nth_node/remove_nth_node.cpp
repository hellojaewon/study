#include <iostream>
#include <cassert>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode * next;

    ListNode (int x)  : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd (ListNode* head, int n) {
        ListNode * n_1 = head;
        ListNode * deleted = head;
        ListNode * end = head;
        for (int i = 0; i < n; i++) {
            end = end->next;
        }
        while (end) {
            n_1 = deleted;
            deleted = deleted->next;
            end = end->next;
        }

        n_1->next = deleted->next;
        if (deleted == head)
            return deleted->next;
        return head;
    }
};

void PrintList (ListNode * head) {
    while (head) {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

ListNode * MakeList (int n) {
    ListNode * head = nullptr;
    ListNode * last = nullptr;
    for (int i = 0; i < n; i++) {
        auto newNode = new ListNode(i+1);
        if (!head) {
            head = newNode;
            last = head;
        }
        else {
            last->next = newNode;
            last = newNode;
        }
    }
    return head;
}

void ReleaseList (ListNode * head) {
    while (head) {
        auto deleted = head;
        head = head->next;
        delete deleted;
    }
}

int main () {
    Solution s;
    auto head = MakeList(5);
    PrintList(head);
    auto removed = s.removeNthFromEnd(head, 2);
    PrintList(removed);
    ReleaseList(head);

    head = MakeList(5);
    PrintList(head);
    removed = s.removeNthFromEnd(head, 5);
    PrintList(removed);
    ReleaseList(head);

    head = MakeList(1);
    PrintList(head);
    removed = s.removeNthFromEnd(head, 1);
    PrintList(removed);
    ReleaseList(head);

    head = MakeList(2);
    PrintList(head);
    removed = s.removeNthFromEnd(head, 2);
    PrintList(removed);
    ReleaseList(head);
    return 0;
}
