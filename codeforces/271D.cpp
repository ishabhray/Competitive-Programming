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
int MOD=1e9+9;

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
        string s,t;
        ll k,p=31,p1=53,m=1e9+9;
        cin>>s>>t>>k;
        int n=s.size();
        set<ii>ans;
        for(int i=0;i<n;i++){
            ll cnt=0,curr=0,curr1=0;
            for(int j=i;j<n;j++){
                (curr*=p)%=m;
                (curr+=s[j]-'a'+1)%=m;
                (curr1*=p1)%=m;
                (curr1+=s[j]-'a'+1)%=m;
                if(t[s[j]-'a']=='0')
                    cnt++;
                if(cnt>k)
                    break;
                //cout<<i<<' '<<j<<' '<<curr<<'\n';
                ans.insert({curr,curr1});
            }
        }
        cout<<ans.size();
    }
}