#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<vector<ll>>> graph(n+1);
    // vector<vector<ll>> dist(n+1, vector<ll>(n+1, LLONG_MAX));
    for(ll i=0;i<m;i++){
        ll a, b, c;
        cin>>a>>b>>c;
        graph[a].push_back({b, c});
    }

    vector<vector<ll>> dist(n+1);

    priority_queue<
        pair<ll,ll>,
        vector<pair<ll,ll>>,
        greater<pair<ll,ll>>
    >pq;
    pq.push({0, 1});
    dist[1].push_back(0);
    while(!pq.empty()){
        auto [cost, u] = pq.top(); pq.pop();

        if(dist[u].size() == k && cost > dist[u].back()){
            continue;
        }

        for(auto& e: graph[u]){
            ll v= e[0], w = e[1];
            ll nw = cost + w;
            if(dist[v].size() < k){
                dist[v].push_back(nw);
                sort(dist[v].begin(), dist[v].end());

                pq.push({nw, v});
            } else if(nw < dist[v].back()){
                dist[v].back() = nw;
                sort(dist[v].begin(), dist[v].end());

                pq.push({nw, v});
            }
        }
    }
    for(ll c: dist[n]){
        cout<<c<<" ";
    }
    cout<<"\n";
    return 0;
}