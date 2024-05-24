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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head , *t = head;
        while(fast && fast->next){a
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                while(t != slow){
                    slow = slow->next;
                    t = t->next;
                }
                return t;
            }
        }

        return nullptr; 
    }
};