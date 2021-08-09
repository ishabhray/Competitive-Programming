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
int ctoi(char c){
    if(c>='A'&&c<='Z') return c-'A';
    return c-'a'+26;
}
int stoi(char a,char b,char c){
    return ctoi(a)*52*52+ctoi(b)*52+ctoi(c);
}
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
        int n;
        cin>>n;
        vv<ii>edges;
        int mx=52*52*52;
        vi cnt(mx,0);
        vi ans(mx,-1);
        vi adj[mx];
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            int m=s.size();
            edges.pb({stoi(s[0],s[1],s[2]),stoi(s[m-3],s[m-2],s[m-1])});
            cnt[edges[i].ff]++;
            adj[edges[i].ss].pb(edges[i].ff);
        }
        queue<int>q;
        for(int i=0;i<mx;i++){
            if(cnt[i]==0){
                ans[i]=0;
                q.push(i);
            }
        }
        while(q.size()){
            int a=q.front();
            q.pop();
            for(int i:adj[a]){
                if(ans[i]==-1){
                    cnt[i]--;
                    if(ans[a]==0){
                        ans[i]=1;
                        q.push(i);
                    }
                    else if(cnt[i]==0){
                        ans[i]=0;
                        q.push(i);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(ans[edges[i].ss]==0) cout<<"Takahashi\n";
            else if(ans[edges[i].ss]==1) cout<<"Aoki\n";
            else cout<<"Draw\n";
        }
    }
}