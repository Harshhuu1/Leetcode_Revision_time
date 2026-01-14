1class Solution {
2public:
3    void rotate(vector<vector<int>>& matrix) {
4        int n=matrix.size();
5        int m=matrix[0].size();
6        // int i=0;
7            for(int i=0;i<n;i++){
8                for(int j=i+1;j<m;j++){
9                 swap(matrix[i][j],matrix[j][i]);
10                 }}
11
12                 for(int i=0;i<n;i++)
13                 {
14                    reverse(matrix[i].begin(),matrix[i].end());
15                 }
16
17            
18            
19            }
20           
21
22        }
23    
24;