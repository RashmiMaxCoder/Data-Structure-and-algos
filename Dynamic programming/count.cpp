long long int count(int S[], int m, int n) 
        {
            
            long long dp[m+1][n+1];
            for(int i=0;i<=n;i++)
            {
                dp[0][i]=0;
            }
            for(int j=0;j<=m;j++)
            {
                dp[j][0]=1;
            }
            
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(S[i-1]>j)
                        dp[i][j]=dp[i-1][j];
                    else
                        dp[i][j]=dp[i][j-S[i-1]] + dp[i-1][j]; 
                }
            }
            return dp[m][n];
        }
