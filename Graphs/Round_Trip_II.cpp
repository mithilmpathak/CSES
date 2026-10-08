#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<ll>> graph;
vector<ll> state;
vector<ll> parent;
ll cyclestart = -1, cycleend = -1;

bool dfs(ll u){
    state[u] = 1;
    for(ll v: graph[u]){
        if(state[v] == 0){
            parent[v] = u;
            if(dfs(v)){
                return true;
            }
        }
        else if(state[v] == 1){
            cyclestart = v;
            cycleend = u;
            return true;
        }
    }
    state[u] = 2;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    graph.resize(n+1);
    state.resize(n+1, 0);
    parent.resize(n+1, -1);

    for(ll i=0;i<m;i++){
        ll a, b;
        cin>>a>>b;
        graph[a].push_back(b);
    }

    for(ll i=1;i<=n;i++){
        if(state[i] == 0){
            if(dfs(i)) break;
        }
    }
    if(cyclestart == -1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    vector<ll> cycle;
    cycle.push_back(cyclestart);

    ll curr = cycleend;
    while(curr != cyclestart){
        cycle.push_back(curr);
        curr = parent[curr];
    }
    cycle.push_back(cyclestart);
    reverse(cycle.begin(),cycle.end());


    cout<<cycle.size()<<"\n";
    for(ll c:cycle){
        cout<<c<<" ";
    }
    cout<<"\n";
    return 0;
}