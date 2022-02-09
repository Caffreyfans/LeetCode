#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* s1 = l1;
        ListNode* s2 = l2;
        ListNode* ret = NULL;
        ListNode* tail = ret;
        char up = 0;
        while (s1 != nullptr && s2 != nullptr) {
            char sum = s1->val + s2->val + up;
            up = sum / 10;
            sum = sum % 10;
            ListNode *node = new ListNode(sum);
            if (ret == NULL) {
                ret = node;
                tail = node;
            } else {
                tail->next = node;
                tail = tail->next;
            }
            s1 = s1->next;
            s2 = s2->next;
        }
        if (s1 == nullptr && s2 == nullptr) {
            if (up != 0) {
                tail->next = new ListNode(up);
            } 
        }
        while (s1 != nullptr) {
            char sum = s1->val + up;
            up = sum / 10;
            sum = sum % 10;
            ListNode *node = new ListNode(sum);
            if (ret == NULL) {
                ret = node;
                tail = node;
            } else {
                tail->next = node;
                tail = tail->next;
            }
            s1 = s1->next;
        }
        while (s2 != nullptr) {
            char sum = s2->val + up;
            up = sum / 10;
            sum = sum % 10;
            ListNode *node = new ListNode(sum);
            if (ret == NULL) {
                ret = node;
                tail = node;
            } else {
                tail->next = node;
                tail = tail->next;
            }
            s2 = s2->next;
        }
        if (up != 0) {
            tail->next = new ListNode(1);
        }
        return ret;
    }
};

int main()
{
    ListNode s1(9);
    ListNode s2(9);
    ListNode s3(9);
    ListNode s4(9);
    ListNode s5(9);
    ListNode s6(9);
    ListNode s7(9);
    s1.next = &s2;
    s2.next = &s3;
    s3.next = &s4;
    s4.next = &s5;
    s5.next = &s6;
    s6.next = &s7;

    Solution solution;
    ListNode *ret = solution.addTwoNumbers(&s1, &s4);
    ListNode *p = ret;
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    return 0;
}

