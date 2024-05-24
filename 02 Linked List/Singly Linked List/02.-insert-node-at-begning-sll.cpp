
Node* insertAtFirst(Node* list, int newValue) {
    // Write your code here
    Node *h = new Node(newValue);
    if(list == nullptr){
        return h;
    }
    h->next = list;
    return h;
}