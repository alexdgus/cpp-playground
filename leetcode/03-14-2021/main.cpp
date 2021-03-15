/* You are given the head of a linked list, and an integer k. */

/* Return the head of the linked list after swapping the values of the kth node
 * from the beginning and the kth node from the end (the list is 1-indexed). */

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

/* A very long and not very well thought out solution */
class Solution {
public:
    int countNodes(ListNode* head) {
        int count = 1;
        while(head->next) {
            head = head->next;
            count++;
        }
        return count;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* iter = head;
        ListNode* front = nullptr;
        ListNode* tempFront = nullptr;
        int i = 1;
        
        int nodes = countNodes(head);
        if(nodes == 1) {
            return head;
        } else if(nodes == k) {
            k = 1;
        } else if(k * 2 - 1 == nodes) {
            return head;
        } else if(k > nodes / 2) {
            k = nodes - k + 1;
        }

        if(k == 1) {
            tempFront = head;
        } else {
            //cout << "pt 1 " << iter->val << "\n";
            for(; i < k - 1; i++) {
                iter = iter->next;
                //cout << "pt 1 " << iter->val << "\n";
            }
            tempFront = iter;
            front = iter->next;
        }

        //cout << "pt 2 " << iter->val << "\n";
        while(iter->next) {
            iter = iter->next;
            //cout << "pt 2 " << iter->val << "\n";
            i++;
        }

        int bk = i - k + 1;
        //cout << "bk " << bk << " i " << i << "\n";
        if(k == 1) {
            bk--;
        } else if(k == bk) {
            return head;
        } else if (k == bk - 1) {
            tempFront->next = front->next;
            ListNode* tempNext = tempFront->next->next;
            tempFront->next->next = front;
            front->next = tempNext;
            return head;
        }
        
        iter = tempFront;
        //cout << "pt 3 " << iter->val << "\n";
        for(int j = k; j < bk; j++) {
            iter = iter->next;
            //cout << "pt 3 " << iter->val << "\n";
        }
        
        ListNode* tempBack = iter;
        ListNode* back = iter->next;

        if(k == 1) {
            tempBack->next = tempFront;
            head = back;
            head->next = tempFront->next;
            tempFront->next = nullptr;
        } else {
            tempFront->next = back;
            ListNode* backNext = back->next;
            back->next = front->next;
            tempBack->next = front;
            front->next = backNext;
        }

        return head;
    }
};