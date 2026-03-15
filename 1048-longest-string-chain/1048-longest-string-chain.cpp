class Solution {
public:
    bool ispred(string s, string t){
        if(s.length()<=t.length()) return false;
        if(s.length()-t.length()!=1){ return false;}
        int i=0;
        int j=0;
        while(i<s.length() && j<t.length()){
            if(t[j]==s[i]){
                j++;
            }
            i++;
        }
        return j==t.length();
    }
    int lis(int i,int prev,vector<string>& words,vector<vector<int>> &dp){
        if(i==words.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int take=0;
        if(prev==-1 || ispred(words[i],words[prev])){
            take=1+lis(i+1,i,words,dp);
        }
        int skip=lis(i+1,prev,words,dp);
        return  dp[i][prev+1]=max(take,skip);
    }
    int tab(vector<string>& words){
        int n=words.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int prev=n-1;prev>=-1;prev--){
                int take=0;
            if(prev==-1 || ispred(words[i],words[prev])){
                take=1+dp[i+1][i+1];
            }
            int skip=dp[i+1][prev+1];
            dp[i][prev+1]=max(take,skip);
            }
        }
        return dp[0][0];
    }
    int space(vector<string>& words){
        int n=words.size();
        vector<int>next(n+1,0);
        vector<int>curr(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int prev=n-1;prev>=-1;prev--){
                int take=0;
            if(prev==-1 || ispred(words[i],words[prev])){
                take=1+next[i+1];
            }
            int skip=next[prev+1];
            curr[prev+1]=max(take,skip);
            }
            next=curr;
        }
        return next[0];
        }
    int oneDLis(vector<string>& words){
        int n=words.size();
        vector<int>dp(n+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(ispred(words[i],words[j])){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        return 1+*max_element(begin(dp),end(dp));
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        sort(words.begin(),words.end(),[](string &a , string &b){
            return a.length()<b.length();
        });
        // return tab(0,-1,words,dp);
        // return tab(words);
        // return space(words);
        return oneDLis(words);
    }
};