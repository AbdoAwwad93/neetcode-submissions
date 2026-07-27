/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3 = new ListNode();
        if(!list1) return list2;
        if(!list2) return list1;
        if (list1->val <= list2->val) {
            list3->val = list1->val;
            list1 = list1->next;
        } else {
            list3->val = list2->val;
            list2 = list2->next;
        }
        ListNode* curr = list3;

        while (list2 && list1) {
            ListNode* newNode = new ListNode();
            curr->next = newNode;
            if (list1->val <= list2->val) {
                newNode->val = list1->val;
                list1 = list1->next;
            } else {
                newNode->val = list2->val;
                list2 = list2->next;
            }
            curr = newNode;
        }
        if(list1) curr->next= list1;
        else if(list2) curr->next = list2;
        return list3;
    }
};
