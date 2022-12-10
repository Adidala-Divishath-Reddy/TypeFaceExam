//this is the function which will be called first.
void solve(vector<vector<int>> &matrix){
    int minRow, maxRow, minCol, maxCol;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].szie(); j++){
            if(matrix[i][j]){
                minRow = matrix.size();
                maxRow = -1;
                minCol = matrix[0].size();
                maxCol = -1;
                dfs(image, i, j, minRow, maxRow, minCol, maxCol);
                float centreX, centreY;
                int width, height;
                centreY = (float)minRow + (float)((float)maxRow - (float)minRow)/2.0;
                centreX = (float)minCol + (float)((float)maxCol - (float)minCol)/2.0;
                width = maxCol - minCol + 1;
                height = maxRow - minRow + 1;
                cout<<"["<<centreX << ","<<centreY<<","<< width<<","<<height<<"]";
            }
        }
    }
}

void dfs(vector<vector<int>> &image, int i , int j, int &minRow, int &maxRow, int &minCol, int &maxCol){
    if(i <  0 || i >= image.size() || j < 0 || j >= image[0].size() || !image[i][j])
        return;
    
    image[i][j] = 0;
    minRow = min(minRow, i);
    maxRow = max(maxRow, i);
    minCol = min(minCol, j);
    maxCol = max(maxCol, j);
    
    dfs(image, i - 1, j, minRow, maxRow, minCol, maxCol);
    dfs(image, i, j + 1, minRow, maxRow, minCol, maxCol);
    dfs(image, i + 1, j, minRow, maxRow, minCol, maxCol);
    dfs(image, i, j - 1, minRow, maxRow, minCol, maxCol);
    dfs(image, i - 1, j - 1, minRow, maxRow, minCol, maxCol);
    dfs(image, i - 1, j + 1, minRow, maxRow, minCol, maxCol);
    dfs(image, i + 1, j - 1, minRow, maxRow, minCol, maxCol);
    dfs(image, i + 1, j + 1, minRow, maxRow, minCol, maxCol);
    
}

