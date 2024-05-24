
Node *deleteLast(Node *list){
    // Write your code here
    if(!list || !list->next){
        return nullptr;
    }
    Node *trav = list, *prev = list;
    while(trav->next){
        prev = trav;
        trav = trav->next;
    }
    prev->next=nullptr;
    free(trav);
    return list;
}


// delete a node in LL, head not given,[Leetcode]

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};