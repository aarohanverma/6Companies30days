class Solution {
private:
    vector<int> cities;
    vector<int> rank;
public:
    
    int find(int city) {
        if(city == cities[city]) return city;
        return cities[city] = find(cities[city]);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int m = isConnected.size(); // number of cities
        int n = isConnected[0].size();
        cities.resize(m);
        rank.resize(m, 1);
        int size = m;
       
        for(int i=0; i<m; ++i){
            cities[i] = i;
        }
        
        auto _union = [&](int A, int B){
            int rootA = find(A);
            int rootB = find(B);
   
            if(rootA != rootB) {
                if(rank[rootA] > rank[rootB]) {
                    cities[rootB] = rootA;
                } else if(rank[A] < rank[rootB]) {
                    cities[rootA] = rootB;
                } else {
                    cities[rootA] = rootB;
                    rank[rootB] += 1;
                }
            }
            size -= 1;
        };
        
        
        for(int i=0; i<m; ++i)
        {
            for(int j=i+1; j<n; ++j)
            {
                if(isConnected[i][j]) 
                {
                    if(find(i) != find(j))
                    {
                        // if two cities have different root node 
                        // => they are not connected
                        _union(i, j);
                    }
                }
            }
        }
        
        return size;
    }
};
