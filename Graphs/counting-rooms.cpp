#include<bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<ll>> moves = {
    {1,0}, {-1, 0}, {0, 1}, {0, -1}
};

bool validid(ll i, ll j, ll n, ll m){
    return i>=0 && i < n && j>=0 && j<m;
}
ll solve(vector<vector<char>>& mp, vector<vector<bool>>& visited, ll i, ll j){
    ll n = mp.size(), m = mp[0].size();
    visited[i][j] = true;
    queue<pair<ll,ll>> q;
    q.push({i,j});
    // ll count = 1;
    while(!q.empty()){
        auto& it = q.front();
        q.pop();
        ll x = it.first, y = it.second;
        // if(x == 0 || x == n-1 || y == 0 || y == m-1) count = 0;
        for(ll i=0;i < 4;i++){
            ll nx = x + moves[i][0], ny = y + moves[i][1];
            if(validid(nx, ny,n,m) && !visited[nx][ny]  && mp[nx][ny] == '.'){
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return 1;
}

int main(){
    ll n, m;
    cin>>n>>m;
    vector<vector<char>> mp(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>mp[i][j];
        }
    }
    ll ans = 0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(mp[i][j] == '.' && !visited[i][j]){
                ans += solve(mp, visited, i, j);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}