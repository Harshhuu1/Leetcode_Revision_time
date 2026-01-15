1class Solution {
2public:
3
4    int ncr(int n, int r){
5        long long  res=1;
6        for(int i=0;i<r;i++){
7            res=res*(n-i);
8            res=res/(i+1);
9        }
10        return res;
11
12    }
13    vector<vector<int>> generate(int numRows) {
14        int n=numRows;
15        vector<vector<int>> result;
16
17        // for (int n = 0; n < numRows; n++) {
18        //     vector<int> row;
19        //     long long val = 1;   // nC0 = 1
20
21        //     for (int r = 0; r <= n; r++) {
22        //         row.push_back((int)val);
23
24        //         // next value using nCr formula
25        //         // nC(r+1) = nCr * (n - r) / (r + 1)
26        //         val = val * (n - r) / (r + 1);
27        //     }
28
29        //     result.push_back(row);
30        
31        
32        for(int i=0;i<n;i++){
33            vector<int>row(i+1,1);
34            for(int j= 1;j<i;j++){
35                row[j]=result[i-1][j-1]+result[i-1][j];
36            }
37            result.push_back(row);
38            
39        }
40        
41        return result;
42    }
43};
44