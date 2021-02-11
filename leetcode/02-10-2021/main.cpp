/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    Node* newHead = NULL;
    Node* currentNewNode = NULL;
    Node* currentOriginalNode = head;

    if (head) {
      // Make a deep copy of the original linked list
      newHead = new Node(head->val);
      currentNewNode = newHead;
      while (currentOriginalNode->next) {
        currentNewNode->next = new Node(currentOriginalNode->next->val);
        currentNewNode = currentNewNode->next;
        currentOriginalNode = currentOriginalNode->next;
      }

      // Fill in random pointers
      currentNewNode = newHead;
      currentOriginalNode = head;
      while (currentNewNode && currentOriginalNode) {
        Node* searchNode = currentOriginalNode->random;
        if (currentOriginalNode->random) {
          Node* origTraverse = head;
          Node* newTraverse = newHead;
          while (origTraverse) {
            if (origTraverse == searchNode) {
              currentNewNode->random = newTraverse;
              break;
            } else {
              origTraverse = origTraverse->next;
              newTraverse = newTraverse->next;
            }
          }
        }
        currentNewNode = currentNewNode->next;
        currentOriginalNode = currentOriginalNode->next;
      }
    }

    return newHead;
  }
};