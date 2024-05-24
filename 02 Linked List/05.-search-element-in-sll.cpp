
int searchInLinkedList(Node<int> *head, int k) {
    Node<int> *trav = head;
    while(trav){
        if(trav->data == k){
            return 1;
        }
        trav = trav->next;
    }
    return 0;
}