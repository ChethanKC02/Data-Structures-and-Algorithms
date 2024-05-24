Node* constructLL(vector<int>& arr) {
    Node *head;
    Node *trav = head;
    for(int i:arr){
        Node *n= new Node(i);
        trav->next = n;
        trav=trav->next;
    }
    trav->next = nullptr;
    return head;
}