int LongestBitonicSequence(vector<int>a)
	{
	    // code here
	    int n = a.size();
	   int lis[n];
       lis[0]=1;
       for(int i=1;i<n;i++)
       {
           lis[i]=1;
           for(int j=0;j<i;j++)
           {
               if(a[j]<a[i])
               lis[i]=max(lis[i],lis[j]+1);
           }
       }
       
       int lds[n];
       lds[n - 1] = 1;
       for(int i = n - 2; i >= 0; i--)
       {
           lds[i] = 1;
           for(int j = i; j < n; j++)
           {
               if(a[j]<a[i])
               lds[i]=max(lds[i],lds[j]+1);
           }
       }
       
       int max = lis[0] + lds[0] - 1;
        for (int i = 1; i < n; i++)
        	if (lis[i] + lds[i] - 1 > max)
        		max = lis[i] + lds[i] - 1;
		
        return max;
       
	}
