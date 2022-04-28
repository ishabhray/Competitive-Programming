#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vv vector

int bankersAndClients(int c, int b,vector< vector<int> > &t) {
// Complete the bankersAndClients function .
    int MAX=(1<<b);
    vv<vi> dp(MAX, vi(b, 1e9));
    for(int i=0;i<b;i++) dp[1<<i][i]=t[i][0];
    for (int i = 1; i < c; i++)
    {
        vv<vi> curr(MAX, vi(b, 1e9));
        for (int mask = 0; mask < MAX; mask++)
        {
            int mn = 1e9;
            for (int j = 0; j < b; j++)
            {
                if (mask & (1 << j))
                    mn = min(mn, dp[mask][j]);
            }
            for (int j = 0; j < b; j++)
            {
                if (!(mask & (1 << j)))
                {
                    curr[mask ^ (1 << j)][j] = min(curr[mask ^ (1 << j)][j], mn + t[j][i]);
                }
                else
                {
                    curr[mask][j] = min(curr[mask][j], dp[mask][j] + t[j][i]);
                }
            }
        }
        swap(dp,curr);
    }
    int ans = 1e9;
    for (int i = 0; i < b; i++)
        ans = min(ans, dp[(MAX) - 1][i]);
    return ans;
  

}

int main() {
	clock_t start, end;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    start=clock();
	int b, c;
	cin >> c >> b;
	int answer;
	vector<vector<int>> time(b, vector<int>(c));
	for (int i = 0; i < b; i++) {

		for (int j = 0; j < c; j++) {
			cin >> time[i][j];
		}
	}
	answer = bankersAndClients(c, b, time);
    end=clock();
    double time_taken=double(end - start)/ double(CLOCKS_PER_SEC);
    cout<<"Execution Time: "<<time_taken<<" seconds\n";
	// Do not remove below line
	cout << answer << endl;
	// Do not print anything after this line

	return 0;
}