
int searchInLinkedList(Node<int> *head, int k) {
    // Write your code here.
    Node<int> *trav = head;
    while(trav){
        if(trav->data == k){
            return 1;
        }
        trav = trav->next;
    }
    return 0;
}