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
int MOD=1e9+7;
ll power(ll a, ll b){//a^b
    ll res=1;
    a=a%MOD;
    while(b>0){
        if(b&1){res=(res*a)%MOD;b--;}
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
ll fermat_inv(ll y){return power(y,MOD-2);}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}
ll dp[(1<<20)];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        vi idx[20];
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            x--;
            idx[x].pb(i);
        }
        ll cnt[20][20];
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                if(j==i||idx[i].empty()||idx[j].empty())
                    continue;
                int x=0,y=0;
                while(x<idx[i].size()&&y<idx[j].size()){
                    if(idx[i][x]<idx[j][y])
                        x++;
                    else
                        cnt[i][j]+=idx[i].size()-x,y++;
                }
            }
        }
        int tot=(1<<20);
        for(int i=0;i<tot;i++)
            dp[i]=1e15;
        dp[0]=0;
        for(int i=0;i<tot;i++){
            for(int j=0;j<20;j++){
                if(i&(1<<j))
                    continue;
                int nmask=i|(1<<j);
                ll sum=0;
                for(int k=0;k<20;k++){
                    if(i&(1<<k))
                        sum+=cnt[k][j];
                }
                dp[nmask]=min(dp[nmask],dp[i]+sum);
            }
        }
        cout<<dp[tot-1];
    }
}