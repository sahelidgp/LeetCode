class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));

        int tm = 0;
        int freshCount = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},tm});
                    vis[i][j] = 2; //mark as rotten
                }else if(grid[i][j] == 1){
                    freshCount++;
                }

            }
        }
        int cnt = 0;
        int t=0;
         int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
             t = q.front().second;

            q.pop();

           
            for(int i=0;i<4;i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];

                if(nrow >=0 && nrow<n && ncol >= 0 && ncol<m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol] = 2;
                    cnt++;

                }
            }
        }
        if(freshCount != cnt)return -1;
        else return t;
    }
};