1class Solution {
2public:
3    string largestOddNumber(string num) {
4        string ans="";
5        int n=num.length();
6        for(int i=n-1;i>=0;i--){
7           
8           int digit=num[i]-'0';
9           if(digit%2==1){
10            return num.substr(0,i+1);
11           }
12            // break;
13            }
14           
15        
16         return "";}
17
18    
19};