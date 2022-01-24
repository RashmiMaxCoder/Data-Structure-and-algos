#include<bits/stdc++.h>
using namespace std;
int ceilIdx(int tail[], int l, int r, int key)
{
  while (r > l) {
    int m = l + (r - l) / 2;
    if (tail[m] >= key)
      r = m;
    else
      l = m + 1;
  }

  return r;
}

int longestSubsequence(int n, int arr[])
{
  int tail[n];
  int len = 1;

  tail[0] = arr[0];

  for (int i = 1; i < n; i++) {

    if (arr[i] > tail[len - 1])
    {
      tail[len] = arr[i];
      len++;
    }
    else {
      int c = ceilIdx(tail, 0, len - 1, arr[i]);

      tail[c] = arr[i];
    }
  }

  return len;
}

int Maximum_Non_overlapping_Bridges(vector<pair<int,int>> &vec)
{
    sort(vec.begin(),vec.end());
    int lis[vec.size()];
    int i = 0;
    for(auto a : vec)
    {
        lis[i++] = a.second;
    }
    
    return longestSubsequence(vec.size(),lis);
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> vec;
    
    while(n--)
    {
        int a,b;
        cin >> a >> b;
        vec.push_back({a,b});
    }
    
    cout << Maximum_Non_overlapping_Bridges(vec);
}
