1class Solution {
2public:
3    void setZeroes(vector<vector<int>>& matrix) {
4       bool firstRowImpacted=false;
5       bool firstColImpacted=false;
6       int n=matrix.size();
7       int m=matrix[0].size();
8
9        for(int i=0;i<n;i++){
10            if(matrix[i][0]==0){
11                firstColImpacted=true;
12                break;
13            }}
14
15        for(int j=0;j<m;j++){
16            if(matrix[0][j]==0){
17                firstRowImpacted=true;
18                break;
19            }}
20
21        for(int i=1;i<n;i++){
22            for(int j=1;j<m;j++){
23                if(matrix[i][j]==0){
24                    matrix[i][0]=0;
25                    matrix[0][j]=0;
26            }
27
28        }}
29
30            
31
32        for(int i=1;i<n;i++){
33        for(int j=1;j<m;j++){
34            if(matrix[i][0]==0 || matrix[0][j]==0){
35                matrix[i][j]=0;
36                
37            }
38
39        }}
40
41        if(firstRowImpacted){
42            for(int j=0;j<m;j++){
43                matrix[0][j]=0;
44            }
45
46        }
47
48        if(firstColImpacted){
49            for(int i=0;i<n;i++){
50                matrix[i][0]=0;
51            }
52
53        }
54
55       
56
57
58            
59            
60
61
62        
63
64
65    }
66};