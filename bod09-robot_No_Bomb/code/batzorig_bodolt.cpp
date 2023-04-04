#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[100][100],i,j,dp[100][100],mode=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<endl;
    dp[0][n-1]=a[0][n-1];
    for(i=1;i<n;i++){
        if(mode==0)
        {
        dp[i][n-1]=a[i][n-1]+dp[i-1][n-1];
        }
        else{
            dp[i][n-1]=-1;
        }
        if(dp[i][n-1]==-1)
        {
            mode=1;
        }
    }
    mode=0;
    for(i=n-2;i>=0;i--){
        if(mode==0)
        {
        dp[0][i]=a[0][i]+dp[0][i+1];
        }
        else{
            dp[0][i]=-1;
        }
        if(dp[0][i]==1)
        {
            mode=1;
        }
    }
    for(i=1;i<n;i++)
    {
        for(int j=n-2;j>=0;j--)
        {
            dp[i][j]=a[i][j]+max(dp[i][j+1],dp[i-1][j])    ;
        }
    }
    for(i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
