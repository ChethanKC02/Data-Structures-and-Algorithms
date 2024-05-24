
int length(Node *head){
	//Write your code here
    if(head == nullptr){
        return 0;
    }
    return 1 + length(head->next) ;

}