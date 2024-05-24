class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy,*trav = head;
        while(trav && trav->next){
            ListNode *first = trav, *second = trav->next;
            prev->next = second;
            first->next = second->next;
            second->next = first;
            prev = trav;
            trav = trav->next;
        }
        return dummy->next;
    }
};