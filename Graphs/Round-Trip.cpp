#include <bits/stdc++.h>
using namespace std;
#define int long long
// typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define Endl '\n'

#define Roshan()                          \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(0);                       \
        cout.tie(0);                      \
    }
vector<int> path;
vector<int> parentArr;
bool dfs(vector<vector<int>> &adj, int parent, int node, vector<int> &vis)
{
    vis[node] = 1;
    parentArr[node] = parent;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(adj, node, it, vis) == true)
                return true;
        }
        else if (parent != it)
        {
            int current = node;
            path.push_back(current);
            while (current != it)
            {
                current = parentArr[current];
                path.push_back(current);
            }
            path.push_back(node);              // To close the cycle
            reverse(path.begin(), path.end()); // To get the cycle in correct order
            return true;
        }
    }
    // path.pop_back();
    return false;
}
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n, 0);
    parentArr.resize(n);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && dfs(adj, -1, i, vis) == true)
        {
            cout << path.size() << endl;
            for (auto it : path)
            {
                cout << it + 1 << " ";
            }
            cout << Endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << Endl;
}

int32_t main()
{
    Roshan();
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        Solve();
    }
    return 0;
}