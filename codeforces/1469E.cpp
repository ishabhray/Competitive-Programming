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
int vis[2000010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    cin>>te;
    for(int i=0;i<=2e6+5;i++)
        vis[i]=-1;
    while(te--){
        int n,k;
        string s;
        cin>>n>>k>>s;
        int x=min(k,20);
        int curr=0;
        for(int i=0;i<x;i++)
            if(s[n-1-i]=='0')
                curr+=(1<<i);
        int cnt=0;
        for(int i=0;i<k-x;i++)
            if(s[n-1-x-i]=='0')
                cnt++;
        if(!cnt)
            vis[curr]=te;
        for(int i=1;i<n-k+1;i++){
            if(s[n-i]=='0')
                curr--;
            curr/=2;
            if(s[n-i-x]=='0')
                curr+=(1<<(x-1)),cnt--;
            if(s[n-i-k]=='0')
                cnt++;
            if(!cnt)
                vis[curr]=te;
        }
        int ans;
        for(int i=0;i<=2e6+5;i++){
            if(vis[i]!=te){
                ans=i;
                break;
            }
        }
        if(k<=x&&ans>=(1<<x))
            cout<<"NO\n";
        else{
            cout<<"YES\n";
            for(int i=k-1;i>=0;i--){
                if(i>=x)
                    cout<<0;
                else if(ans&(1<<i))
                    cout<<1;
                else
                    cout<<0;
            }
            cout<<'\n';
        }
    }
}