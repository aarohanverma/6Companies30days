class Solution {
public:
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    bool isValid(int i,int j,int n)
    {
        return i>=0 and j>=0 and i<n and j<n;
    }
    int maxDistance(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int dis[n][n];
        int sum=0;
        bool vis[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                vis[i][j]=false;
            }
        }
        queue<vector<int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum+=grid[i][j];
                if(grid[i][j]==1)
                {
                    q.push({i,j,0});
                    vis[i][j]=true;
                }
            }
        }
        if(sum==0 or sum==pow(n,2))
            return -1;
        int ans=0;
        while(!q.empty())
        {
            int i=q.front()[0];
            int j=q.front()[1];
            int d=q.front()[2];
            q.pop();
            dis[i][j]=d;
            ans=max(ans,dis[i][j]);
            for(int k=0;k<4;k++)
            {
                if(isValid(i+dx[k],j+dy[k],n) and !vis[i+dx[k]][j+dy[k]])
                {
                    vis[i+dx[k]][j+dy[k]]=true;
                    q.push({i+dx[k],j+dy[k],d+1});
                }
            }
        }
        return ans;
    }
};
