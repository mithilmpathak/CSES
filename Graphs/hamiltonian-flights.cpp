#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;
const int N = 20;

ll dp[(1<<N)][N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n);
    for(ll i=0;i<m;i++){
        ll u, v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
    }

    dp[1][0] = 1;

    for(ll i=0;i<(1<<n);i++){
        for(ll j=0;j<n;j++){
            if(!dp[i][j]) continue;
            for(ll k: adj[j]){

                if(i & (1<<k)) continue;
                dp[i | (1<<k)][k] += dp[i][j];
                dp[i | (1<<k)][k] %= MOD;
            }
        }
    }
    cout<<dp[(1<<n) - 1][n-1]<<"\n";
    return 0;
}