class Solution {
private:
    ListNode *reverse(ListNode *head){
        ListNode *prev = nullptr, *cur = head;
        ListNode *temp;
        while(cur){
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp; 
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1,head);
        ListNode *prev = dummy;
        bool flag = false;
        while(prev){
            ListNode *l1 = prev,*l2 = prev->next;
            int i=0;
            for( i;i<k && prev->next; i++){
                prev = prev->next;
            }
            if(i!=k) break;
            ListNode *r2 = prev->next;
            prev->next = nullptr;
            l1->next = reverse(l2);
            if(l2)l2->next = r2;
            prev = l2;
        }
        return dummy->next;
    }
};