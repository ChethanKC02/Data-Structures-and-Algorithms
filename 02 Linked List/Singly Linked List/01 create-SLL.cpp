Node* constructLL(vector<int>& arr) {
    // Write your code here
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