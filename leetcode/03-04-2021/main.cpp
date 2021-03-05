/* Write a program to find the node at which the intersection of two singly
 * linked lists begins. */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(ListNode *head) {
        int i = 0;
        while(head) {
            i++;
            head = head->next;
        }
        return i;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int aNodes = countNodes(headA);
        int bNodes = countNodes(headB);
        ListNode *largeHead = aNodes > bNodes ? headA : headB;
        ListNode *smallHead = aNodes > bNodes ? headB : headA;
        int largeSize = max(aNodes, bNodes);
        int smallSize = min(aNodes, bNodes);
        for(int i = 0; i < largeSize - smallSize; i++) {
            if(largeHead) {
                largeHead = largeHead->next;
            }
        }
        for(int i = 0; i < smallSize; i++) {
            if(largeHead == smallHead) {
                return largeHead;
            }
            largeHead = largeHead->next;
            smallHead = smallHead->next;
        }
        return nullptr;
    }
};