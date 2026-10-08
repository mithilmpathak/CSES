#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<vector<vector<ll>>> graph(n+1);
    for(ll i=0;i<m;i++){
        ll a, b, c;
        cin>>a>>b>>c;
        graph[a].push_back({b, c});
    }

    vector<ll> dist(n+1, LLONG_MAX);
    dist[1] = 0;
    priority_queue<
        vector<ll>,
        vector<vector<ll>>,
        greater<vector<ll>>
    >pq;
    pq.push({0, 1});
    while(!pq.empty()){
        auto it = pq.top(); pq.pop();

        ll curr = it[0], u = it[1];

        if(dist[u] < curr) continue;

        for(auto& e : graph[u]){
            ll v = e[0], w = e[1];

            ll nw = curr + w;
            if(dist[v] > nw){
                dist[v] = nw;
                pq.push({nw, v});
            }
        }
    }

    for(ll i=1;i<=n;i++) cout<<dist[i]<<" ";
    cout<<"\n";
    return 0;
}