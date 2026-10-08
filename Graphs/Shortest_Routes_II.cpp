#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, m, q;
    cin>>n>>m>>q;

    vector<vector<ll>> graph(n+1, vector<ll>(n+1, LLONG_MAX));

    for(ll i=0;i<m;i++){
        ll a, b, c;
        cin>>a>>b>>c;
        graph[a][b] = min(graph[a][b],c);
        graph[b][a] = min(graph[b][a], c);
    }

    for(ll i=1;i<=n;i++) graph[i][i] = 0;

    // vector<vector<ll>> dist(n+1, vector<ll>(n+1, 1e10));

    for(ll k = 1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                if(graph[i][k] == LLONG_MAX || graph[k][j] == LLONG_MAX) continue;
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    while(q--){
        ll a,b;
        cin>>a>>b;
        if(graph[a][b] == LLONG_MAX){
            cout<<"-1\n";
        } else{
            cout<<graph[a][b]<<"\n";
        }
    }

    return 0;
}