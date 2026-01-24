1class Solution {
2public:
3    bool oneMap(string s,string t){
4            unordered_map<char,int>mp;
5        if (s.size()!=t.size())
6            return false;
7        for(int i=0;i<s.size();i++){
8            mp[s[i]]++;
9            mp[t[i]]--;
10        }
11        for(auto i:mp){
12            if(i.second!=0){
13                return false;
14            }
15        }
16        return true;
17        }
18    bool noMap(string s,string t){
19            sort(s.begin(),s.end());
20            sort(t.begin(),t.end());
21            return s==t;
22        }
23
24    bool isAnagram(string s, string t) {
25        //One map method
26        return noMap(s,t);
27
28        
29
30    }
31};