#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const char dir[] = {'D', 'U', 'R', 'L'};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> grid[i];
    }

    // Find your starting position and monster positions
    int startX = -1, startY = -1;
    queue<pair<int, int>> monsterQueue;
    vector<vector<int>> monsterTime(n, vector<int>(m, -1));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 'A')
            {
                startX = i;
                startY = j;
            }
            else if (grid[i][j] == 'M')
            {
                monsterQueue.push({i, j});
                monsterTime[i][j] = 0;
            }
        }
    }

    // BFS for monsters to calculate minimum time to reach each cell
    while (!monsterQueue.empty())
    {
        auto it = monsterQueue.front();
        int x = it.first;
        int y = it.second;
        monsterQueue.pop();

        for (int d = 0; d < 4; ++d)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && monsterTime[nx][ny] == -1)
            {
                monsterTime[nx][ny] = monsterTime[x][y] + 1;
                monsterQueue.push({nx, ny});
            }
        }
    }

    // BFS for you to find a valid path
    queue<pair<int, int>> yourQueue;
    vector<vector<int>> yourTime(n, vector<int>(m, -1));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> direction(n, vector<char>(m, ' '));

    yourQueue.push({startX, startY});
    yourTime[startX][startY] = 0;

    bool escaped = false;
    int escapeX = -1, escapeY = -1;

    while (!yourQueue.empty())
    {
        auto it = yourQueue.front();
        int x = it.first;
        int y = it.second;
        yourQueue.pop();

        // Check if you reached the boundary
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
        {
            escaped = true;
            escapeX = x;
            escapeY = y;
            break;
        }

        for (int d = 0; d < 4; ++d)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && yourTime[nx][ny] == -1)
            {
                // Check if you can reach this cell before any monster
                if (monsterTime[nx][ny] == -1 || yourTime[x][y] + 1 < monsterTime[nx][ny])
                {
                    yourTime[nx][ny] = yourTime[x][y] + 1;
                    parent[nx][ny] = {x, y};
                    direction[nx][ny] = dir[d];
                    yourQueue.push({nx, ny});
                }
            }
        }
    }

    // Output the result
    if (!escaped)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;

        // Reconstruct the path
        string path;
        int x = escapeX, y = escapeY;
        while (x != startX || y != startY)
        {
            path += direction[x][y];
            auto it = parent[x][y];
            x = it.first;
            y = it.second;
        }

        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        cout << path << endl;
    }

    return 0;
}