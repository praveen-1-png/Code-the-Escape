#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int n, m;
char maze[MAXN][MAXN];
bool visited[MAXN][MAXN];
pair<int, int> parent[MAXN][MAXN];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
pair<int, int> start, end_pos;

// TODO 1: Check if (x, y) is a valid move
bool isValid(int x, int y) {
    // Fill this function
    if(x<0||x>=n||y<0||y>=m)
    return false; // Placeholder
    if(visited[x][y]){
        return false;
    }
    if(maze[x][y]=='0'){
        return false;
    }
    return true;
}

// TODO 2: BFS Implementation
void bfs() {
    queue<pair<int, int>> q;
    visited[start.first][start.second] = true;
    q.push(start);

    while (!q.empty()) {
        pair<int, int> cur = q.front(); 
        q.pop();
        if (cur == end_pos){  break;}
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(isValid(nx,ny)){
                visited[nx][ny]=true;
                parent[nx][ny]=cur;
                q.push({nx,ny});
            }

            // Fill the condition and logic
        }
       
    }
}

// TODO 3: DFS Implementation
bool dfs(int x, int y) {
    // Fill this function (recursive DFS)
    visited[x][y] = true;
    
    // If we reached the end position
    if (x == end_pos.first && y == end_pos.second) {
        return true;
    }
    
    // Explore neighbors in all 4 directions
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (isValid(nx, ny)) {
            // Set parent before recursion
            parent[nx][ny] = {x, y};
            if (dfs(nx, ny)) {
                return true;
            }
        }
    }
    return false; // Placeholder
}

// TODO 4: Reconstruct and print the path
void reconstructPath(pair<int, int> end_point) {
    // Fill this function
    // Check if end point was reached
    if (parent[end_point.first][end_point.second].first == -1 && 
        parent[end_point.first][end_point.second].second == -1 && 
        end_point != start) {
        cout << "No path found." << endl;
        return;
    }
    
    vector<pair<int, int>> path;
    pair<int, int> current = end_point;
    
    // Follow parent links backward from end to start
    while (current.first != -1 && current.second != -1) {
        path.push_back(current);
        if (current == start) break;
        current = parent[current.first][current.second];
    }
    
    // Reverse the path to get start-to-end order
    reverse(path.begin(), path.end());
    
    if (path.empty() || path[0] != start) {
        cout << "No path found." << endl;
        return;
    }
    
    cout << "Path found! Length: " << path.size() << endl;
    cout << "Path coordinates: ";
    for (int i = 0; i < path.size(); ++i) {
        cout << "(" << path[i].first << "," << path[i].second << ")";
        if (i < path.size() - 1) cout << " -> ";
    }
    cout << endl;
    
    // Mark the path in the maze (optional visualization)
    for (const auto& p : path) {
        if (maze[p.first][p.second] != 'S' && maze[p.first][p.second] != 'E') {
            maze[p.first][p.second] = '*';
        }
    }
    


}


void printMaze() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << maze[i][j];
        }
        cout << '\n';
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j];
            if (maze[i][j] == 'S') start = {i, j};
            if (maze[i][j] == 'E') end_pos = {i, j};
        }
    }
    for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        parent[i][j] = {-1, -1};
    }
}

    // Uncomment the one you want to test
     bfs();
     dfs(start.first, start.second);

    reconstructPath(end_pos);
     //printMaze();

    return 0;
}