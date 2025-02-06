#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
int n, m;
char grid[N][N];
pair<int, int> parent[N][N];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char movDir[] = {'U', 'D', 'L', 'R'};
pair<int, int> st, ed;
bool vis[N][N];

bool isvalid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && !vis[x][y]);
}

void bfs()
{
    queue<pair<int, int>> q;
    q.push(st);
    vis[st.first][st.second] = true;

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int x = it.first;
        int y = it.second;
        if (make_pair(x, y) == ed)
            return;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isvalid(nx, ny))
            {
                vis[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }
}

void Ans()
{
    vector<char> ans;
    pair<int, int> curr = ed;

    while (curr != st)
    {
        int px = parent[curr.first][curr.second].first;
        int py = parent[curr.first][curr.second].second;

        for (int i = 0; i < 4; i++)
        {
            if (px + dx[i] == curr.first && py + dy[i] == curr.second)
            {
                ans.push_back(movDir[i]);
                break;
            }
        }
        curr = {px, py};
    }

    reverse(ans.begin(), ans.end());
    cout << "YES" << endl
         << ans.size() << endl;
    for (auto c : ans)
        cout << c;
    cout << endl;
}

void Solve()
{
    cin >> n >> m;
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                st = {i, j};
            if (grid[i][j] == 'B')
                ed = {i, j};
        }
    }
    bfs();
    if (!vis[ed.first][ed.second])
    {
        cout << "NO" << endl;
    }
    else
    {
        Ans();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        Solve();
    }
    return 0;
}