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

ll dp[1005][1005][2],a[1005][1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n,m,q;
        cin>>n>>m>>q;
        ll ans=0,curr=n*m;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                dp[i][j][0]=1+dp[i][j+1][1];
                dp[i][j][1]=1+dp[i+1][j][0];
                ans+=dp[i][j][0]+dp[i][j][1];
            }
        }
        for(int qq=0;qq<q;qq++){
            int x,y;
            cin>>x>>y;
            x--,y--;
            if(a[x][y]) curr++;
            else curr--;
            a[x][y]=!a[x][y];
            ans-=dp[x][y][0]+dp[x][y][1];
            if(a[x][y]) dp[x][y][0]=dp[x][y][1]=0;
            else dp[x][y][0]=1+dp[x][y+1][1],dp[x][y][1]=1+dp[x+1][y][0];
            ans+=dp[x][y][0]+dp[x][y][1];
            while(x>=0&&y>=0){
                if(x-1>=0&&!a[x-1][y]){
                    ans-=dp[x-1][y][1];
                    dp[x-1][y][1]=1+dp[x][y][0];
                    ans+=dp[x-1][y][1];
                }
                if(y-1>=0&&!a[x][y-1]){
                    ans-=dp[x][y-1][0];
                    dp[x][y-1][0]=1+dp[x][y][1];
                    ans+=dp[x][y-1][0];
                }
                if(x-1>=0&&y-1>=0&&!a[x-1][y-1]){
                    ans-=dp[x-1][y-1][0]+dp[x-1][y-1][1];
                    dp[x-1][y-1][0]=1+dp[x-1][y][1];
                    dp[x-1][y-1][1]=1+dp[x][y-1][0];
                    ans+=dp[x-1][y-1][0]+dp[x-1][y-1][1];
                }
                x--,y--;
            }
            cout<<ans-curr<<'\n';
        }
    }
}