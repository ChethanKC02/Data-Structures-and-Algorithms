
class Solution {
private:
    ListNode *merge(ListNode *l,ListNode *r){
        ListNode *head = new ListNode(0);
        ListNode *trav = head;
        while(l && r){
            if(l->val < r->val){
                trav->next = l;
                l = l->next;
            }
            else{
                trav->next = r;
                r = r->next;
            }
            trav = trav->next;
        }
        if(l){
            trav->next = l;
        }
        else if(r){
            trav->next = r;
        }
        return head->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *slow = head, *fast = head->next->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *l = sortList(slow->next);
        slow->next = nullptr;
        ListNode *r = sortList(head);
        return merge(l,r);        
    }
};