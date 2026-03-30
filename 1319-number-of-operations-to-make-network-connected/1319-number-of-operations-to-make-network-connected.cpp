class Solution {
public:
    class DSU{
        public:
        int find(int x , vector<int> &par){
            if(par[x]!=x){
                par[x]=find(par[x],par);
            }
        
        return par[x];}
    
        void comb(int x ,int y, vector<int> &rank,vector<int> &par){
            int ra=find(x,par);
            int rb=find(y,par);
            if(ra==rb) return;
            if(rank[ra]<rank[rb]) par[ra]=rb;
            else if(rank[ra]>rank[rb]) par[rb]=ra;
            else{
                par[rb]=ra;
                rank[ra]++;
            }

        }};
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu;
        // vector<vector<int>>adj(n);
        vector<int>par(n,0);
        vector<int>rank(n,0);
        // int count=0;
        if(connections.size()<n-1) return -1;
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        for(auto edge:connections){
            dsu.comb(edge[0],edge[1],rank,par);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(dsu.find(i,par)==i) count++;
        }
        return count-1;
          
    


    }
};