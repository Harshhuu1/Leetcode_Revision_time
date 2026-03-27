class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto u:times){
            adj[u[0]].push_back({u[1],u[2]});
        }
        vector<int>time(n+1,1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minheap;
        minheap.push({0,k});
        time[k]=0;
        while(!minheap.empty()){
            auto [dist , node]=minheap.top();minheap.pop();
            if(dist>time[node]){
                continue;
            }
            for(auto i : adj[node]){
                int nbr=i.first;
                int wt=i.second;
                if(time[nbr]>dist+wt){
                    time[nbr]=dist+wt;
                    minheap.push({time[nbr],nbr});
                }
            }
        }
        int maxi=-1;
        for(int i=1;i<=n;i++){
            if(time[i]==1e9) return -1; 
            maxi=max(maxi,time[i]);
        }
        return maxi;
    }
};