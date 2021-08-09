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
set<int>xo;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int te=1;
    cin>>te;
    while(te--){
        int n;
        cin>>n;
        int a[n+1],pre[n+1]={0};
        for(int i=0;i<n;i++){
            cin>>a[i+1];
            pre[i+1]=pre[i]^a[i+1];
        }
        xo.clear();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=i;j++){
                xo.insert(pre[i]^pre[j-1]);
            }
        }
        int ans=0;
        for(int i:xo){
            int curr=0;
            unordered_map<int,bool>hash;
            hash[0]=1;
            for(int j=1;j<=n;j++){
                int req=i^pre[j];
                if(hash.find(req)!=hash.end()){
                    curr++;
                    hash.clear();
                }
                hash[pre[j]]=1;
            }
            ans=max(ans,curr);
        }
        cout<<ans<<'\n';
    }
}