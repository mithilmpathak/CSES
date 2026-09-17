#include<bits/stdc++.h>
using namespace std;

#define ll long long

class DSU{
public:
    ll n;
    vector<ll> parent, rank;
    DSU(ll n){
        this->n = n;
        this->parent.resize(n,0);
        for(ll i=0;i<n;i++) parent[i] = i;
        this->rank.resize(n,0);
    }

    ll find(ll u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    void unionn(ll u, ll v){
        u = find(u);
        v = find(v);

        if(rank[u] == rank[v]){
            parent[v] = u;
            rank[u]++;
        } else if(rank[u] < rank[v]){
            parent[u] = v;
        } else{
            parent[v] = u;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> roads(m, vector<ll>(2));
    for(ll i=0;i<m;i++){
        cin>>roads[i][0]>>roads[i][1];
    }

    DSU dsu(n+1);
    for(auto& road : roads){
        dsu.unionn(road[0], road[1]);
    }

    vector<ll> repr;
    for(ll i=1; i<=n;i++){
        if(dsu.find(i) == i){
            repr.push_back(i);
        }
    }
    cout<<repr.size() - 1<<"\n";
    for(ll i=1; i<repr.size();i++){
        cout<<repr[i-1]<<" "<<repr[i]<<"\n";
    }
    return 0;

}