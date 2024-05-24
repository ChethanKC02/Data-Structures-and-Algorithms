
int length(Node *head){
    if(head == nullptr){
        return 0;
    }
    return 1 + length(head->next) ;
}