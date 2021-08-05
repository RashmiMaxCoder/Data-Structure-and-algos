void solve( Node* root,Node* &head, Node* &prev, int &f )
    {
        if(root == NULL) return;
        
        solve(root->left,head,prev,f);
        if(head == NULL)
        {
            f =1;
            head = root;
            prev = root;
        }
        else
        {
            prev->right = root;
            prev->right->left = prev;
            prev = prev->right;
        }
        solve(root->right,head,prev,f);
    }
    Node * bToDLL(Node *root)
    {
        // your code here
        int f = 0;
        Node *head = NULL;
        Node *prev = NULL;
        solve(root,head,prev,f);
        
        return head;
    }
