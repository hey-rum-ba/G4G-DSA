class Solution
{
    public:
    //Function to count nodes of a linked list.
    int getCount(struct Node* head){
    
         int cnt=0;
         Node* ptr=head;
        while(ptr!=NULL) {ptr=ptr->next; cnt++;}
        return cnt;
    
    }
};