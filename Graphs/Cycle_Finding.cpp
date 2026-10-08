#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct Edge{
    ll u, v, w;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, m;
    cin>>n>>m;
    vector<Edge> edges(m);
    for(auto& e: edges){
        cin>>e.u>>e.v>>e.w;
    }

    vector<ll> dist(n+1, 0);
    vector<ll> par(n+1, -1);


    int x = -1;
    for(int i=1;i<=n;i++){
        x = -1;
        for(auto [u,v,w] : edges){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                par[v] = u;

                x = v;
            }
        }
    }

    if(x == -1){
        cout<<"NO\n";
        return 0;
    }

    for(ll i=0;i<n;i++){
        x = par[x];
    }

    vector<ll> cycle;
    
    int curr = x;

    do{
        cycle.push_back(curr);
        curr = par[curr];
    } while(curr != x);

    cycle.push_back(x);

    reverse(cycle.begin(), cycle.end());
    cout<<"YES\n";

    for(ll v: cycle){
        cout<<v<<" ";
    }
    cout<<"\n";

    return 0;
}