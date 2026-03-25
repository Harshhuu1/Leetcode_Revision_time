class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};
    typedef pair<int,pair<int,int>> p;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n  = heights.size();
        int m  = heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        priority_queue< p,vector<p>, greater<p>>pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        // q.push({0,0});
        int mini=1e9;
        while(!pq.empty()){
            auto [ eff , cor]=pq.top();pq.pop();
            auto [i ,j]=cor;

            if(i == n-1 && j == m-1){
                return eff;
            }

            for(int k=0;k<4;k++){
                int ii=i+dx[k];
                int jj=j+dy[k];

                if( ii < n && jj < m && ii >=0 && jj >= 0){
                    int new_eff=max(eff,abs(heights[ii][jj]-heights[i][j]));
                    if(dist[ii][jj]>new_eff){
                        dist[ii][jj]=new_eff;
                        pq.push({new_eff,{ii,jj}});
                    }
                    }
                }
            }
            
        
        return -1;

    }
};