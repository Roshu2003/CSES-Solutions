#include <bits/stdc++.h>
using namespace std;
// #define int long long
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define Endl '\n'
const int MOD = 1e9 + 7;

#define Roshan()                          \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(0);                       \
        cout.tie(0);                      \
    }

vector<int> color; // -1 means uncolored
bool isBipartiteBFS(int n, vector<vector<int>> &adj)
{

    for (int i = 0; i < n; i++)
    { // In case of disconnected components
        if (color[i] == -1)
        {
            queue<int> q;
            q.push(i);
            color[i] = 1;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node])
                {
                    if (color[neighbor] == -1)
                    {
                        color[neighbor] = (color[node] == 1 ? 2 : 1); // Assign opposite color
                        q.push(neighbor);
                    }
                    else if (color[neighbor] == color[node])
                    {
                        return false; // Conflict detected
                    }
                }
            }
        }
    }
    return true; // No conflicts, it's bipartite
}
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    color.resize(n, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isBipartiteBFS(n, adj) == false)
    {
        cout << "IMPOSSIBLE" << Endl;
        return;
    }
    for (auto it : color)
        cout << it << " ";
    cout << Endl;
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