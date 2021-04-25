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

ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}

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
        int n,m;
        cin>>n>>m;
        string a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int cntr[n][4][2],cntc[m][4][2];
        map<char,int>mp;
        mp['A']=0;
        mp['C']=1;
        mp['G']=2;
        mp['T']=3;
        memset(cntr,0,sizeof(cntr));
        memset(cntc,0,sizeof(cntc));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cntr[i][mp[a[i][j]]][j%2]++;
                cntc[j][mp[a[i][j]]][i%2]++;
            }
        }
        string seq="ACGT";
        vv<string> poss;
        do{
            poss.pb(seq);
        }while(next_permutation(all(seq)));
        string ans;
        int o,mx=0;
        for(int c=0;c<24;c++){
            int cnt=0;
            cout<<poss[c]<<'\n';
            for(int i=0;i<n;i++){
                if(i%2==0)
                    cnt+=cntr[i][mp[poss[c][0]]][0]+cntr[i][mp[poss[c][1]]][1];
                else
                    cnt+=cntr[i][mp[poss[c][2]]][0]+cntr[i][mp[poss[c][3]]][1];
            }
            cout<<cnt<<' ';
            if(cnt>mx){
                mx=cnt;
                ans=poss[c];
                o=0;
            }
            cnt=0;
            for(int i=0;i<m;i++){
                if(i%2==0)
                    cnt+=cntc[i][mp[poss[c][0]]][0]+cntc[i][mp[poss[c][1]]][1];
                else
                    cnt+=cntc[i][mp[poss[c][2]]][0]+cntc[i][mp[poss[c][3]]][1];
            }
            cout<<cnt<<'\n';
            if(cnt>mx){
                mx=cnt;
                ans=poss[c];
                o=1;
            }
        }
        cout<<mx<<' '<<ans<<' '<<o;
    }
}