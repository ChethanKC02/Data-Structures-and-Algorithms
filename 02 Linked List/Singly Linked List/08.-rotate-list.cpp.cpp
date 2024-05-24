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
private:
    int height(ListNode *head){
        if(head == nullptr){
            return 0;
        }
        return height(head->next) + 1;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int h = height(head);
        if(h==0){
            return head;
        }
        if(k>h){
            k%=h;
        }
        k = h-k ;
        if(k==0 || k==h){
            return head;
        }
        ListNode *trav = head, *prev = nullptr;
        for(int i=0;i<k;i++){
            // cout<<trav->val<<" ";
            prev = trav;
            trav = trav->next;
        }
        prev->next = nullptr;
        ListNode *Nhead = trav;
        while(trav->next){
            trav = trav->next;
        }
        trav->next = head;
        return Nhead;
    }
};