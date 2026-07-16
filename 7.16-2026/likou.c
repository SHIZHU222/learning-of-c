#define _CRT_SECURE_NO_WARNINGS 
bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize) {
    int x0 = coordinates[0][0], y0 = coordinates[0][1];
    int dx = coordinates[1][0] - x0;
    int dy = coordinates[1][1] - y0;

    for (int i = 2; i < coordinatesSize; i++) {
        int xi = coordinates[i][0], yi = coordinates[i][1];
        if (dy * (xi - x0) != dx * (yi - y0))
            return false;
    }
    return true;
}