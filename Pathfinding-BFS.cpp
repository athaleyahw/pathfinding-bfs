#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int row;
    int col;
};

bool isValid(int row, int col, int rows, int cols, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    return (row >= 0 && row < rows &&
        col >= 0 && col < cols &&
        grid[row][col] != '#' &&
        !visited[row][col]);
}

void printGrid(vector<vector<char>>& grid) {
    for (auto& row : grid) {
        for (auto cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<char>> grid = {
        {'S', '.', '.', '#', '.', '.'},
        {'.', '#', '.', '#', '.', '.'},
        {'.', '#', '.', '.', '.', '#'},
        {'.', '.', '#', '#', '.', '.'},
        {'#', '.', '#', 'E', '.', '.'}
    };

    int rows = grid.size();
    int cols = grid[0].size();

    queue<Point> q;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<Point>> parent(rows, vector<Point>(cols));

    Point start, end;

    // Find start and end
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 'S') start = { i, j };
            if (grid[i][j] == 'E') end = { i, j };
        }
    }

    q.push(start);
    visited[start.row][start.col] = true;

    int directions[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

    bool found = false;

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        if (current.row == end.row && current.col == end.col) {
            found = true;
            break;
        }

        for (auto& dir : directions) {
            int newRow = current.row + dir[0];
            int newCol = current.col + dir[1];

            if (isValid(newRow, newCol, rows, cols, grid, visited)) {
                q.push({ newRow, newCol });
                visited[newRow][newCol] = true;
                parent[newRow][newCol] = current;
            }
        }
    }

    if (found) {
        Point step = end;
        while (!(step.row == start.row && step.col == start.col)) {
            if (grid[step.row][step.col] != 'E')
                grid[step.row][step.col] = '*';
            step = parent[step.row][step.col];
        }

        cout << "Shortest Path Found:\n";
        printGrid(grid);
    }
    else {
        cout << "No path found.\n";
    }

    return 0;
}