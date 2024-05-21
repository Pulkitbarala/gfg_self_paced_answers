void booleanMatrix(int mat[ROWS][COLS], int m, int n) {
    for (int i = 0; i < m; i++) {
        // Set flag for the presence of 1 in the row
        bool containsOne = false;
        
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                containsOne = true;
                // Set the first element of the row to 1
                mat[i][0] = 1;
                break;
            }
        }
        
        // If the row contains 1, update the entire row to 1
        if (containsOne) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = 1;
            }
        }
    }
}