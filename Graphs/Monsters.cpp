#include<bits/stdc++.h>
using namespace std;

#define ll long long

int moves[4][2] = {
    {0,1}, {0,-1}, {1, 0}, {-1, 0}
};

char dir[4] = {
    'R', 'L', 'D', 'U'
};


// void printway(vector<vector<char>>& grid, vector<vector<ll>>& par, ll x, ll y){
//     string s = "";
//     ll i = x;
//     ll j = y;

//     while(par[i][j] != '$'){
//         s += dir[par[i][j]];

//         i -= moves[par[i][j]][0];
//         j -= moves[par[i][j]][1];
//     }
//     reverse(s.begin(), s.end());
//     cout<<s.size()<<"\n";
//     for(char& c: s){
//         cout<<c;
//     }
//     cout<<"\n";
// }

void printway(vector<vector<pair<ll,ll>>>& par, ll x, ll y){
    string s;
    while(par[x][y] != make_pair(-2LL, -2LL)){
        auto [px, py] = par[x][y];
        if(px == x && py == y -1) s += 'R';
        else if(px == x && py == y + 1) s += 'L';
        else if(px == x-1 && py == y) s += 'D';
        else if(px == x+1 && py == y) s += 'U';

        x = px;
        y = py;
    }
    reverse(s.begin(), s.end());
    cout<<s.size()<<"\n";
    cout<<s<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<pair<ll,ll>>> par(n, vector<pair<ll,ll>>(m, {-1, -1}));
    // vector<vector<ll>> par(n, vector<ll>(m, '!'));
    vector<vector<bool>> visited(n, vector<bool>(m,false));
    vector<vector<ll>> time(n, vector<ll>(m,LLONG_MAX));

    using Element = tuple<ll, ll, ll>;
    queue<Element> q;
    queue<Element> monsters;

    pair<ll,ll> start = {-1, -1};

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j] == 'A'){
                q.push(Element(0LL, i, j));
                start.first = i;
                start.second = j;
                // par[i][j] = '$';
                visited[i][j] = true;
            }
            if(grid[i][j] == 'M') {
                monsters.push(Element(0LL, i, j));
                time[i][j] = 0;
            }
        }
    }
    par[start.first][start.second] = {-2LL, -2LL};

    while(!monsters.empty()){
        auto it = monsters.front(); monsters.pop();
        ll t = get<0>(it);
        ll i = get<1>(it);
        ll j = get<2>(it);

        if(time[i][j] < t) continue;

        for(int k = 0; k<4;k++){
            ll ni = i + moves[k][0];
            ll nj = j + moves[k][1];

            if(ni >= 0 && ni<n && nj>=0 && nj<m && grid[ni][nj] != '#'){
                ll nt = t + 1;
                if(time[ni][nj] > nt){
                    time[ni][nj] = nt;
                    monsters.push(Element(nt, ni, nj));
                }
            }
        }
    }

    bool found = false;

    

    while(!q.empty()){
        auto it = q.front(); q.pop();
        ll t = get<0>(it);
        ll i = get<1>(it);
        ll j = get<2>(it);

        if(i == 0 || i == n-1 || j == 0 || j == m-1){
            cout<<"YES\n";
            // printway(grid, par, i, j);
            printway(par, i, j);
            found = true;
            break;
        }

        for(int k = 0; k<4; k++){
            ll ni = i + moves[k][0];
            ll nj = j + moves[k][1];

            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj] != '#' && time[ni][nj] > t + 1 && !visited[ni][nj]){
                visited[ni][nj] = true;
                par[ni][nj] = {i,j};
                // par[ni][nj] = k;

                q.push(Element(t + 1, ni, nj));
            }
        }
    }
    if(!found){
        cout<<"NO\n";
    }
    return 0;
}