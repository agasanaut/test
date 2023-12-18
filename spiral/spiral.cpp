#include <iostream>

// Define the maximum size for the matrix
const int MAX_SIZE = 3;

void printSpiralOrder(int matrix[][MAX_SIZE], int m, int n) {
    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // Print top row
        for (int i = left; i <= right; ++i) {
            std::cout << matrix[top][i] << " ";
        }
        top++;

        // Print right column
        for (int i = top; i <= bottom; ++i) {
            std::cout << matrix[i][right] << " ";
        }
        right--;

        // Print bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                std::cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }

        // Print left column
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                std::cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
}

int main() {
    // Example usage
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int m = MAX_SIZE, n = MAX_SIZE;

    std::cout << "Spiral Order: ";
    printSpiralOrder(matrix, m, n);

    return 0;
}
