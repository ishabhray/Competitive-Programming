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
bool ismask(int x,int a){
    for(int i=0;i<9;i++){
        if(x&(1<<i))
            if(!(a&(1<<i)))
                return false;
    }
    return true;
}
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
        int n,m;
        cin>>n>>m;
        int b[512]={0},cnt[512]={0};
        vi idx[512],a[512];
        for(int i=0;i<n;i++){
            int sz;
            cin>>sz;
            int curr=0;
            for(int j=0;j<sz;j++){
                int x;
                cin>>x;
                x--;
                curr|=(1<<x);
            }
            b[curr]++;
        }
        for(int i=0;i<512;i++){
            int f=0;
            do{
                cnt[i]+=b[f];
            }while(f=(f-i)&i);
        }
        for(int i=0;i<m;i++){
            int w,sz;
            cin>>w>>sz;
            int curr=0;
            for(int j=0;j<sz;j++){
                int x;
                cin>>x;
                x--;
                curr|=(1<<x);
            }
            if(a[curr].empty()){
                a[curr].pb(w);
                idx[curr].pb(i+1);
            }
            else if(a[curr].size()==1){
                a[curr].pb(w);
                idx[curr].pb(i+1);
                if(a[curr][0]>a[curr][1]){
                    swap(a[curr][0],a[curr][1]);
                    swap(idx[curr][0],idx[curr][1]);
                }
            }
            else{
                if(w>=a[curr][1])
                    continue;
                a[curr][1]=w,idx[curr][1]=i+1;
                if(a[curr][0]>a[curr][1]){
                    swap(a[curr][0],a[curr][1]);
                    swap(idx[curr][0],idx[curr][1]);
                }
            }
            
        }
        int mx=0,mn=INT_MAX,id1=-1,id2=-1;
        for(int i=0;i<512;i++){
            if(a[i].empty())
                continue;
            for(int j=0;j<512;j++){
                if(a[j].empty()||j==i&&a[j].size()<2)
                    continue;
                int curr=a[i][0];
                if(j==i)
                    curr+=a[i][1];
                else
                    curr+=a[j][0];
                ll c=cnt[i|j];
                if(c>mx)
                    mx=c,mn=curr,id1=i,id2=j;
                else if(c==mx&&curr<mn)
                    mn=curr,id1=i,id2=j;
            }
        }
        if(id1==id2)
            cout<<idx[id1][0]<<' '<<idx[id1][1];
        else
            cout<<idx[id1][0]<<' '<<idx[id2][0];
    }
}