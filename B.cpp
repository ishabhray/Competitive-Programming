#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector
#define all(v) (v).begin(),(v).end()
#define MAXN 300005

ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}

int main()
{
    clock_t start, end;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    start=clock();
    int n,k,d,m;
    cin>>n>>k>>d>>m;
    int a[n];
    for(int &i:a) cin>>i;
    vv<vi>dp(k+1,vi(d+1,-1e9));
    dp[0][0]=0;
    int ans=0;
    for(int i=0;i<n;i++){
        vv<vi>curr(k+1,vi(d+1,-1e9));
        for(int j=0;j<=k;j++){
            for(int x=0;x<=d;x++){
                if(j!=k) curr[j+1][d]=max(curr[j+1][d],dp[j][x]);
                if(x) curr[j][x-1]=max(curr[j][x-1],dp[j][x]+m*a[i]);
                else curr[j][0]=max(curr[j][0],dp[j][0]+a[i]);
            }
        }
        swap(dp,curr);
        // for(int j=0;j<=k;j++){
        //     for(int x=0;x<=d;x++) cout<<dp[j][x]<<' ';
        //     cout<<'\n';
        // }
    }
    for(int i=0;i<=d;i++) ans=max(ans,dp[k][i]);
    end=clock();
    double time_taken=double(end - start)/ double(CLOCKS_PER_SEC);
    cout<<"Execution Time: "<<time_taken<<" seconds\n";
    cout<<ans<<'\n';
}