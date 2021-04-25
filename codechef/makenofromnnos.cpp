#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    int dp1[m+1];
    for(int i=0;i<=m;i++)
        dp1[i]=0;
    dp1[0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j+a[i]<=m;j++){
            if(dp1[j]>0)
                dp1[j+a[i]]+=dp1[j];
        }
    }
    for(int i=0;i<=m;i++)
        cout<<dp1[i]<<' ';
    cout<<'\n';
}