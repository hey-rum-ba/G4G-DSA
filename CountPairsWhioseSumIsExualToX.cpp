class Solution{
  public:
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        int count = 0;
     
    unordered_set<int> us;

    while (head1 != NULL)
    {
        us.insert(head1->data);   
      
        head1 = head1->next;
    }

    while (head2 != NULL)   
    {
        if (us.find(x - head2->data) != us.end())
            count++;
 
        head2 = head2->next;   
    }
   
    return count;
    }

};