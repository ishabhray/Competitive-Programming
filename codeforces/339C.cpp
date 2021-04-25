#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector
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
bool prime[1000001];
vi primes;
void SieveOfEratosthenes(int n) 
{ 
    memset(prime, true, sizeof(prime)); 
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for(int p=2;p<1000001;p++)
        if(prime[p])
            primes.pb(p);
}
bool vis[11][11][1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    //cin>>t;
    //SieveOfEratosthenes(1000000);
    while(t--){
        string s;
        int m;
        cin>>s>>m;
        int cnt=0;
        vi v;
        for(int i=0;i<10;i++){
            if(s[i]=='1'){
                cnt++;
                v.pb(i+1);
            }
        }
        queue<pair<ii,int> >q;
        q.push({{0,0},0});
        bool ans=false;
        memset(vis,0,sizeof(vis));
        vis[0][0][0]=1;
        pair<ii,int>p;
        map<pair<ii,int>,pair<ii,int> >back;
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            int bal=a.ff.ff,prev=a.ff.ss,mov=a.ss;
            if(mov==m){
                ans=true;
                p=a;
                break;
            }
            for(int i:v){
                if(i==prev||i<=bal||vis[i-bal][i][mov+1])
                    continue;
                vis[i-bal][i][mov+1]=1;
                q.push({{i-bal,i},mov+1});
                back[{{i-bal,i},mov+1}]=a;
            }
        }
        if(ans){
            cout<<"YES\n";
            stack<int>s;
            do{
                s.push(p.ff.ss);
                p=back[p];
            }while(p.ff.ff!=0&&p.ff.ss!=0);
            while(!s.empty()){
                cout<<s.top()<<' ';
                s.pop();
            }
        }
        else
            cout<<"NO\n";
    }

}