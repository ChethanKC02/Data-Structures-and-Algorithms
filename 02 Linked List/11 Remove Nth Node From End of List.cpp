class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr ){
            return nullptr;
        }
        ListNode  *cur = head;
        while(n--){
            cur = cur->next;
        }
        ListNode *trav = head;
        if(cur == nullptr){
            return head->next;
        }
        while(cur->next){
            cur = cur->next;
            trav = trav->next;
        }
        trav->next = trav->next->next;
        return head;
    }
};