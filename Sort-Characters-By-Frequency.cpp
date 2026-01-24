1class Solution {
2public:
3   typedef pair<char, int> p;
4    string heap(string s){
5        string ans="";
6        unordered_map<char,int>mp;
7        for(auto ch:s){
8            mp[ch]++;
9        }
10        priority_queue<p> pq;
11        for(auto i:mp){
12            pq.push({i.second,i.first});
13        }
14        while(!pq.empty()){
15            auto [freq,ch]=pq.top();
16            pq.pop();
17            ans.append(freq,ch);
18        }
19
20        return ans;
21    }
22    string vector1(string s){
23        string ans="";
24        vector<p>freq(256,{0,0});
25       for (unsigned char c : s) {
26        freq[c].first = c;
27        freq[c].second++;
28    }
29        
30        auto lambda=[&](p &a, p&b){
31            return a.second>b.second;
32        };
33        sort(begin(freq),end(freq),lambda);
34        for(auto i:freq){
35            if (i.second>0){
36                ans.append(i.second,i.first);
37            }
38        }
39        return ans;
40        
41    }
42
43    string buckertSort(string s){
44        unordered_map<char,int>mp;
45        vector<string>bucket(s.size()+1);
46        string ans="";
47        for(auto i:s){
48            mp[i]++;
49        }
50        for(auto it:mp){
51            bucket[it.second].append(it.second,it.first);
52
53        }
54        for(int i=bucket.size()-1;i>0;i--){
55            ans+=bucket[i];
56        }
57        return ans;
58    }
59    string frequencySort(string s) {
60        return buckertSort(s);
61
62    }
63};