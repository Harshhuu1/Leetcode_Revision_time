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
23    bool OOnemethod(string s, string t){
24        vector<int>freq(26,0);
25        if (s.size()!=t.size()){
26            return false;
27        }
28        for(int i=0;i<s.size();i++){
29            freq[s[i]-'a']++;
30            freq[t[i]-'a']--;
31
32        }
33        for (int i=0;i<26;i++){
34            if(freq[i]!=0){
35            return false;
36            break;}
37        }
38        return true;
39    }
40    bool isAnagram(string s, string t) {
41        //One map method
42        // return noMap(s,t);
43        return OOnemethod(s,t);
44
45    }
46};