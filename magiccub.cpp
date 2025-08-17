#include <iostream>
#include <vector>
using namespace std;

// Function to print the square
void printSquare(const vector<vector<int>>& square) {
    int n = square.size();
    int magicSum = n * (n*n + 1) / 2;
    cout << "\nMagic Square of size " << n 
         << " (magic sum = " << magicSum << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << square[i][j] << "\t";
        cout << endl;
    }
}

// For odd n (Siamese method)
vector<vector<int>> magicOdd(int n) {
    vector<vector<int>> square(n, vector<int>(n, 0));

    int num = 1;
    int i = 0, j = n / 2;  // Start at top middle

    while (num <= n*n) {
        square[i][j] = num; // Place number
        num++;

        int newI = (i - 1 + n) % n;  // Move up (wrap around)
        int newJ = (j + 1) % n;      // Move right (wrap around)

        if (square[newI][newJ] != 0) {
            // If cell already filled, move down instead
            i = (i + 1) % n;
        } else {
            i = newI;
            j = newJ;
        }
    }
    return square;
}

// For doubly even n (n % 4 == 0)
vector<vector<int>> magicDoublyEven(int n) {
    vector<vector<int>> square(n, vector<int>(n));

    int num = 1;
    // Fill sequentially
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            square[i][j] = num++;

    // Flip certain cells
    int maxVal = n*n + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i % 4 == j % 4) || ((i % 4 + j % 4) == 3)) {
                square[i][j] = maxVal - square[i][j];
            }
        }
    }
    return square;
}

int main() {
    int n;
    cout << "Enter n (size of magic square): ";
    cin >> n;

    if (n < 3) {
        cout << "Magic square not possible for n < 3.\n";
        return 0;
    }

    vector<vector<int>> square;

    if (n % 2 == 1) {
        square = magicOdd(n); // Odd
    } else if (n % 4 == 0) {
        square = magicDoublyEven(n); // Doubly even
    } else {
        cout << "Singly even n (like 6, 10, 14) not handled in this simple version.\n";
        return 0;
    }

    printSquare(square);
    return 0;
}
