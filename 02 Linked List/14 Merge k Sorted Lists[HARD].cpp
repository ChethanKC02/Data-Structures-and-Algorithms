class Solution {
private:
    ListNode *sort(ListNode *l1,ListNode *l2){
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }
        if(l1->val < l2->val){
            l1->next = sort(l1->next,l2);
            return l1;
        }
        l2->next = sort(l1,l2->next);
        return l2;
    }
public:
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        if(lists.size() == 0){
            return nullptr;
        }
        ListNode *first = lists[0]; 
        for(int i=1;i<lists.size();i++){
            if(lists[i] == nullptr){
                continue;
            }
            first = sort(first,lists[i]);
        }
        return first;
    }
};