class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        queue<pair<int,pair<int,int>>> q; // {dist, {row,col}}
        q.push({1,{0,0}});
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)return -1; 

        if(n-1 == 0)return 1;
        vector<vector<int>>dist (n,vector<int>(n,1e9));
        dist[0][0] = 0;
        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            // go to the neighbours
            for(int dRow=-1;dRow<=1;dRow++){
                for(int dCol=-1;dCol<=1;dCol++){
                    int nRow = row + dRow;
                    int nCol = col + dCol;

                if(nRow >= 0 && nRow < n &&  nCol >= 0 && nCol < n  && grid[nRow][nCol] == 0 && dis+1 < dist[nRow][nCol]){
                    dist[nRow][nCol] = dis+1;
                    if(nRow == n-1 && nCol == n-1)return dist[n-1][n-1];
                    q.push({dist[nRow][nCol],{nRow,nCol}});
                }
                }
            }
        }
        if(dist[n-1][n-1] == 1e9)return -1;
        return dist[n-1][n-1];
    }
};