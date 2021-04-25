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

int cnt[1000005];
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
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        int a[2*n];
        for(int i=0;i<2*n;i++)
            cin>>a[i];
        sort(a,a+2*n,greater<int>());
        bool f=true;
        for(int i=1;i<2*n;i++){
            //cout<<a[i]<<'\n';
            unordered_map<int,int>cnt;
            for(int j=1;j<2*n;j++){
                if(j==i)
                    continue;
                cnt[a[j]]++;
            }
            bool b=true;
            int pre=a[0];
            vv<ii>ans;
            ans.pb({a[0],a[i]});
            for(int j=1;j<2*n;j++){
                if(j==i||!cnt[a[j]])
                    continue;
                //cout<<a[j]<<' '<<pre;
                cnt[a[j]]--;
                if(!cnt[pre-a[j]]){
                    b=false;
                    break;
                }
                cnt[pre-a[j]]--;
                ans.pb({a[j],pre-a[j]});
                pre=a[j];
            }
            //cout<<'\n';
            if(b){
                cout<<"YES\n";
                cout<<ans[0].ff+ans[0].ss<<'\n';
                for(auto j:ans)
                    cout<<j.ff<<' '<<j.ss<<'\n';
                f=false;
                break;
            }
        }
        if(f)
            cout<<"NO\n";
    }
}