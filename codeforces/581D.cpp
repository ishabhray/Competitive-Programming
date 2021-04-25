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
    //factorial(100005);
    while(t--){
        ii side[3];
        cin>>side[0].ff>>side[0].ss>>side[1].ff>>side[1].ss>>side[2].ff>>side[2].ss;
        int area=side[1].ff*side[1].ss+side[2].ff*side[2].ss+side[0].ff*side[0].ss;
        int r=sqrt(area),mx=0;
        for(int i=0;i<3;i++)
            mx=max({mx,side[i].ff,side[i].ss});
        if(r*r!=area||mx>r){
            cout<<-1;
            return 0;
        }
        int arr[]={0,1,2};
        int ans[r][r];
        do{
            for(int o=0;o<8;o++){
                ii s[3];
                for(int i=0;i<3;i++){
                    if(o&(1<<i))
                        s[i]={side[arr[i]].ss,side[arr[i]].ff};
                    else
                        s[i]=side[arr[i]];
                }
                memset(ans,-1,sizeof(ans));
                bool b=true;
                for(int c=0;c<3;c++){
                    int x,y;
                    for(x=0;x<r;x++){
                        for(y=0;y<r;y++){
                            if(ans[x][y]==-1)
                                break;
                        }
                        if(y!=r)
                            break;
                    }
                    for(int i=0;i<s[c].ff;i++){
                        for(int j=0;j<s[c].ss;j++){
                            if(x+i>=r||y+j>=r||ans[x+i][y+j]!=-1){
                                b=false;
                                break;
                            }
                            ans[x+i][y+j]=arr[c];
                        }
                        if(!b)
                            break;
                    }
                    if(!b)
                        break;
                }
                if(b){
                    cout<<r<<'\n';
                    for(int i=0;i<r;i++){
                        for(int j=0;j<r;j++){
                            cout<<(char)('A'+ans[i][j]);
                        }
                        cout<<'\n';
                    }
                    return 0;
                }
            }
        }while(next_permutation(arr,arr+3));
        cout<<-1;
    }
}