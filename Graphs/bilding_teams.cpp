#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,m;
    cin>>n>>m;

    vector<vector<ll>> adj(n+1);

    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n+1, false);
    vector<ll> team(n+1, -1);
    for(ll i=1;i<=n;i++){

        if(visited[i]) continue;

        queue<ll> q;
        q.push(i);
        visited[i] = true;
        team[i] = 1;

        while(!q.empty()){

            ll u = q.front(); q.pop();

            for(ll v : adj[u]){

                if(visited[v]){
                    if(team[v] == team[u]){
                        cout<<"IMPOSSIBLE\n";
                        return 0;
                    }
                    continue;                    
                }

                if(team[u] == 1) team[v] = 2;
                else team[v] = 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }

    for(ll i=1;i<=n;i++){
        cout<<team[i]<<" ";
    }
    cout<<"\n";
    return 0;
}