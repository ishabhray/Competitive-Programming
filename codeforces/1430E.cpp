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
#define MAXN 200005
ll t[4*MAXN]={0};

ll sum(int v,int tl,int tr,int l,int r)
{
    if(l>r)
        return 0;
    if(l==tl&&r==tr)
        return t[v];
    int tm=(tl+tr)/2;
    return sum(v*2,tl,tm,l,min(r,tm))+sum(v*2+1,tm+1,tr,max(l,tm+1),r);
}
void update(int v,int tl,int tr,int pos,int new_val)
{
    if(tl==tr)
        t[v]=new_val;
    else{
        int tm=(tl+tr)/2;
        if(pos<=tm)
            update(2*v,tl,tm,pos,new_val);
        else
            update(2*v+1,tm+1,tr,pos,new_val);
        t[v]=t[2*v]+t[2*v+1];
    }
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
    //factorial(100005);
    while(te--){
        int n;
        string s;
        cin>>n>>s;
        string r=s;
        reverse(all(r));
        set<int> pos[26];
        for(int i=0;i<n;i++){
            pos[s[i]-'a'].insert(i);
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            int j=*pos[r[i]-'a'].begin();
            pos[r[i]-'a'].erase(j);
            ll cnt=sum(1,1,n,j+1,n);
            //cout<<cnt<<'\n';
            update(1,1,n,j,1);
            ans+=j-i+cnt;
            //cout<<ans<<'\n';
        }
        cout<<ans<<'\n';
    }
}