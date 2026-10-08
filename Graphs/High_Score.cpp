#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    // vector<vector<ll>> graph(n+1, vector<ll>(n+1, LLONG_MAX));
    vector<vector<vector<ll>>> graph(n+1);
    vector<vector<ll>> rev(n+1);

    for(ll i=0;i<m;i++){
        ll a, b, x;
        cin>>a>>b>>x;

        graph[a].push_back({b, -x});
        rev[b].push_back(a);
        // graph[b].push_back({a, -x});
    }

    vector<bool> canreach(n+1, false);
    queue<ll> q;
    q.push(n);
    canreach[n] = true;
    while(!q.empty()){
        ll u = q.front(); q.pop();

        for(ll v: rev[u]){
            if(!canreach[v]){
                canreach[v] = true;
                q.push(v);
            }
        }
    }

    const ll INF = 4e18;

    vector<ll> dist(n+1, INF);
    dist[1] = 0;
    for(ll i=1;i<=n-1;i++){
        bool changed = false;
        for(ll u=1;u<=n;u++){
            if(dist[u] == INF) continue;

            for(auto& e: graph[u]){
                ll v= e[0], w = e[1];
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    changed = true;
                }
            }
        }
        if(!changed) break;
    }

    for(ll u=1;u<=n;u++){
        if(dist[u] == INF) continue;
        for(auto& e: graph[u]){
            ll v = e[0], w = e[1];
            if(dist[v] > dist[u] + w && canreach[v]){
                cout<<"-1\n";
                return 0;
            }
        }
    }

    cout<<-dist[n]<<"\n";

    
    return 0;
}