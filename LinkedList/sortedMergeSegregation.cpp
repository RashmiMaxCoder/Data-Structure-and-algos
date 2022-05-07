Node* sortedMerge(Node* head1, Node* head2)  
{  
    if(head1 == NULL)
       return head2;
       
   if(head2 == NULL)
       return head1;
   
   Node *ans = new Node(-1);
   Node *tail = ans;
   
   while(head1 && head2)
   {
       if(head1->data < head2->data)
       {
           tail->next = head1;
           head1 = head1->next;
       }
       else
       {
           tail->next = head2;
           head2 = head2->next;
       }
       tail = tail->next;
   }
   
   if(head1){
       tail->next = head1;
   }
   
   if(head2){
       tail->next = head2;
   }
   
   return ans->next;
}
