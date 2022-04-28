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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    for(int T=1;T<=te;T++){
        string s;
        cin>>s;
        int n=s.size();
        map<char,int>m;
        for(int i=0;i<n;i++) m[s[i]]++;
        int mx=0;
        for(auto i:m) mx=max(mx,i.ss);
        string ans="";
        if(mx>n/2) ans="IMPOSSIBLE";
        else{
            priority_queue<pair<int,char>>v;
            map<char,queue<int>>adj;
            for(int i=0;i<n;i++){
                adj[s[i]].push(i);
            }
            for(char i='a';i<='z';i++) if(m[i]) v.push({m[i],i});
            ans=s;
            while(v.size()){
                if(v.size()==1){
                    char c=v.top().ss;
                    int i=0;
                    while(adj[c].size()){
                        while(ans[i]==c||s[i]==c) i++;
                        swap(ans[i],ans[adj[c].front()]);
                        adj[c].pop();
                    }
                    break;
                }
                else{
                    char x=v.top().ss;
                    v.pop();
                    char y=v.top().ss;
                    v.pop();
                    while(adj[y].size()){
                        swap(ans[adj[x].front()],ans[adj[y].front()]);
                        adj[x].pop();
                        adj[y].pop();
                    }
                    if(adj[x].size()) v.push({adj[x].size(),x});
                }
            }
        }
        cout<<"Case #"<<T<<": "<<ans<<'\n';
    }
}