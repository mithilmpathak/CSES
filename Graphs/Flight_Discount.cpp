#include<bits/stdc++.h>
using namespace std;

#define ll long long

using Edge = pair<ll,ll>;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<vector<Edge>> graph(n+1);
    for(ll i=0;i<m;i++){
        ll a, b, c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }

    vector<vector<ll>> dist(n+1, vector<ll>(2, LLONG_MAX));

    using State = tuple<ll,ll, ll>;
    priority_queue<
        State,
        vector<State>,
        greater<State>
    >pq;

    dist[1][0] = 0;
    pq.push({0, 1, 0});

    while(!pq.empty()){
        auto [cost, u, used] = pq.top(); pq.pop();

        if(cost != dist[u][used]) continue;

        for(auto [v,w] : graph[u]){
            if(dist[v][used] > cost + w){
                dist[v][used] = cost + w;
                pq.push({dist[v][used], v, used});
            }

            if(!used){
                ll ncost = cost + (w >> 1);
                if(dist[v][1] > ncost){
                    dist[v][1] = ncost;
                    pq.push({ncost, v, 1});
                }
            }
        }
    }
    cout<<min(dist[n][0], dist[n][1])<<"\n";
    return 0;
}