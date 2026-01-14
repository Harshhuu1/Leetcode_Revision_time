1class Solution {
2public:
3    int subarraySum(vector<int>& nums, int k) {
4        int count=0;
5        int left=0;
6    
7        int sum=0;
8        unordered_map<int,int>mp;
9        mp[0]=1;
10        for(int right=0;right<nums.size();right++){
11            sum+=nums[right];
12            if(mp.find(sum-k)!=mp.end()){
13                count+=mp[sum-k];
14            }
15            mp[sum]++;
16            }
17        
18        return count;
19    }
20
21};