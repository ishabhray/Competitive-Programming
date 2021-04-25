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
void dfs(int i,vi adj[],int vis[],set<int>&s)
{
    if(vis[i])
        return;
    vis[i]=1;
    s.insert(i);
    for(int j:adj[i])
        dfs(j,adj,vis,s);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
        int n,k;
        cin>>n>>k;
        if(k==1){
            cout<<"! 1"<<endl;
            return 0;
        }
        set<int>posleft;
        set<ii>known;
        for(int i=1;i<=n;i++)
            posleft.insert(i);
        for(int i=0;i<n-k+1;i++){
            cout<<"? ";
            int c=0;
            for(int i:posleft){
                c++;
                cout<<i<<' ';
                if(c==k)
                    break;
            }
            cout<<endl;
            int x,y;
            cin>>x>>y;
            known.insert({y,x});
            posleft.erase(x);
        }
        if(known.size()>=k){
            cout<<"? ";
            int c=0;
            for(auto i:known){
                c++;
                cout<<i.ss<<' ';
                if(c==k)
                    break;
            }
            cout<<endl;
            int x,y;
            cin>>x>>y;
            int ans=0;
            for(auto i:known){
                ans++;
                if(y==i.ff)
                    break;
            }
            cout<<"! "<<ans<<endl;
        }
        else{
            int ans=1;
            for(int i:posleft){
                //cout<<"$$$$$$$"<<ans<<endl;
                auto it=known.begin();
                cout<<"? "<<it->ss<<' ';
                it++;
                cout<<it->ss<<' ';
                for(int j:posleft){
                    if(j==i)
                        continue;
                    cout<<j<<' ';
                }
                cout<<endl;
                int x,y;
                cin>>x>>y;
                if(y!=known.begin()->ff)
                    ans++;
            }
            cout<<"! "<<ans<<endl;
        }
    }
}