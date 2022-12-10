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
                // centre (x,y) will be----> x = (midpoint of left most value and right most value, midpoint of top most value and bottom most value)  
                centreY = (float)minRow + (float)((float)maxRow - (float)minRow)/2.0;
                centreX = (float)minCol + (float)((float)maxCol - (float)minCol)/2.0;
                
                //width will be absolute difference of left most value and right most value
                width = maxCol - minCol + 1;
                //height will be absolute difference of top most value and bottom most value
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
    // Taking the top most enabled pixel
    minRow = min(minRow, i);
    // Taking the bottom most enabled pixel
    maxRow = max(maxRow, i);
    // Taking the left most enabled pixel
    minCol = min(minCol, j);
    // Taking the right most enabled pixel
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

