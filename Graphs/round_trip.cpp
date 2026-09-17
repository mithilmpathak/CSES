#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n,m;
vector<vector<ll>> adj;
vector<ll> parent;
vector<bool> visited;

ll cyclestart = -1;
ll cycleend = -1;

bool dfs(ll u, ll p){
    visited[u] = true;
    parent[u] = p;

    for(ll v : adj[u]){
        if(v == p) continue;

        if(visited[v]){
            cyclestart = v;
            cycleend = u;
            return true;
        }
        if(dfs(v, u)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m;
    adj.resize(n + 1);
    for(ll i=0;i<m;i++){
        ll u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    parent.resize(n+1, -1);
    visited.resize(n+1, false);

    for(ll i=1; i<=n;i++){
        if(!visited[i]){
            if(dfs(i, -1)) break;
        }
    }

    if(cyclestart == -1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    vector<ll> cycle;
    ll curr = cycleend;

    while(curr != cyclestart){
        cycle.push_back(curr);
        curr = parent[curr];
    }

    cycle.push_back(cyclestart);
    cycle.push_back(cycleend);

    cout<<cycle.size()<<"\n";
    for(ll c : cycle){
        cout<<c<<" ";
    }
    cout<<"\n";

    return 0;
}