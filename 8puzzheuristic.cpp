#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

#define N 3  //for 3*3 puzzle

// for directions down, left, up, right
int row[] = {1, 0, -1, 0};
int col[] = {0, -1, 0, 1};


struct Node {
    vector<vector<int>> mat;            //for puzzle configuration
    int x, y;                           //tracks the blank position
    int cost;                           //for manhatan dis
    vector<vector<vector<int>>> path;   
};


int calculateCost(vector<vector<int>> current, vector<vector<int>> goal) {
    int cost = 0;//heuristic func cost =0
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (current[i][j] != 0) {
                for (int x = 0; x < N; x++) {
                    for (int y = 0; y < N; y++) {
                        if (current[i][j] == goal[x][y]) {
                            cost += abs(i - x) + abs(j - y);
                        }
                    }
                }
            }
        }
    }
    return cost;
}

//to Check valid move
bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// Print a board
void printMatrix(const vector<vector<int>>& mat) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----" << endl;
}

// Comparator and goes with lowest cost first
struct compare {
    bool operator()(const Node& a, const Node& b) const {
        return a.cost > b.cost;
    }
};

// Solving  puzzle using Best-First Search
void solve(vector<vector<int>> initial, vector<vector<int>> goal, int x, int y) {
    priority_queue<Node, vector<Node>, compare> pq;

    // Root node
    Node root;
    root.mat = initial;
    root.x = x;
    root.y = y;
    root.cost = calculateCost(initial, goal);
    root.path.push_back(initial);

    pq.push(root);

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        
        if (current.cost == 0) {
            cout << "Solution Path:\n";
            for (auto board : current.path) {
                printMatrix(board);
            }
            return;
        }

        // Move blank in 4 directions
        for (int i = 0; i < 4; i++) {
            int newX = current.x + row[i];
            int newY = current.y + col[i];

            if (isSafe(newX, newY)) {
                Node child;
                child.mat = current.mat;

                // Swap blank with new position
                swap(child.mat[current.x][current.y], child.mat[newX][newY]);

                child.x = newX;
                child.y = newY;
                child.cost = calculateCost(child.mat, goal);

                // Copy path and add new state
                child.path = current.path;
                child.path.push_back(child.mat);

                pq.push(child);
            }
        }
    }
}

int main() {

    vector<vector<int>> initial = {
        {1, 2, 3},
        {5, 6, 0},
        {7, 8, 4}
    };


    vector<vector<int>> goal = {
        {1, 2, 3},
        {5, 8, 6},
        {0, 7, 4}
    };

    // Position of blank in initial
    int x = 1, y = 2;

    solve(initial, goal, x, y);

    return 0;
}
