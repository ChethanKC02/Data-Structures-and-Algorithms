
Node* insertAtFirst(Node* list, int newValue) {
    Node *h = new Node(newValue);
    if(list == nullptr){
        return h;
    }
    h->next = list;
    return h;
}