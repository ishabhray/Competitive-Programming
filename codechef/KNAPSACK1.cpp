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

ll min(ll a,ll b)
{
    return (a<b)?a:b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ll n,wmax;
    cin>>n>>wmax;
    ll w[n],v[n];
    for(ll i=0;i<n;i++)
        cin>>w[i]>>v[i];
    ll dp[n+1][wmax+1];
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=wmax;j++){
            if(i==0||j==0)
                dp[i][j]=0;
            else{
                dp[i][j]=dp[i-1][j];
                if(w[i-1]<=j)
                    dp[i][j]=max(dp[i][j],v[i-1]+dp[i-1][j-w[i-1]]);
            }
        }
    }
    /*for(int i=0;i<=n;i++){
        for(int j=0;j<=wmax;j++)
            cout<<dp[i][j]<<' ';
        cout<<'\n';
    }*/
    cout<<dp[n][wmax];
}