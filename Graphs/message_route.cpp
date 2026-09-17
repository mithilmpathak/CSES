#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n + 1);
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n+1,false);
    vector<ll> parent(n + 1,-1);
    queue<ll> q;
    
    q.push(1);
    visited[1] = true;

    while(!q.empty()){
        ll u = q.front(); q.pop();
        for(ll v: adj[u]){
            if(visited[v]){
                continue; 
            }
            visited[v] = true;
            parent[v] = u;
            q.push(v);
        }
    }

    if(!visited[n]){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    vector<ll> path;
    ll curr = n;
    while(curr != -1){
        path.push_back(curr);
        curr = parent[curr];
    }
    
    reverse(path.begin(), path.end());

    cout<<path.size()<<"\n";
    for(ll p: path){
        cout<<p<<" ";
    }
    cout<<"\n";
    return 0;
}