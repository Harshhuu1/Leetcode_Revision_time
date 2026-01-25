1class Solution {
2public:
3    void nextPermutation(vector<int>& nums) {
4        int index=-1;
5        for(int i=nums.size()-1;i>0;i--){
6            if(nums[i-1]<nums[i]){
7                index=i-1;
8                break;
9            }
10        }
11         if(index==-1){
12            reverse(nums.begin(),nums.end());
13        }
14        sort(nums.begin()+index+1,nums.end());
15        int i=index;
16        while(i<nums.size()){
17            if(nums[index]<nums[i]){
18                swap(nums[index],nums[i]);
19                break;}
20            i++;
21            }
22       
23    }
24};