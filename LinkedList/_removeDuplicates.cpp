Node * removeDuplicates( Node *head) 
    {
     // your code goes here
        unordered_map<int,int> mp;
		Node *curr = head;
		Node *prev = head;
		mp[curr->data] = 1;
		curr = curr->next;
		while (curr!=NULL)
		{
			if(mp[curr->data])
			{
				prev->next = curr->next;
				free(curr);
			}
			else
			{
				mp[curr->data] = 1;
				prev=curr;
			}
			curr = prev->next;
		}
		return head;
    }
