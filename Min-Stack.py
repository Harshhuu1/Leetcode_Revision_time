1class MinStack:
2    # st=[]
3    # ss=[]
4    # COMMENTED CODE IS USIGN O(N) SPACE, NOW I'LL WRITE THE CODE FOR O(1) SPACE 
5    #USE HERE A FLAG - 2*x-MIN_ELE
6    min_ele=0
7    def __init__(self):
8        self.st=[]
9        # self.ss=[]
10
11    def push(self, val: int) -> None:
12        # self.st.append(val)
13        # if not self.ss or val<=self.ss[-1]:
14        #     self.ss.append(val)
15        # return
16        st=self.st
17        if not self.st:
18            
19            st.append(val)
20            MinStack.min_ele=val
21        else:
22            if val>=st[-1]:
23                st.append(val)
24            else:
25                st.append(2*val-MinStack.min_ele)
26                MinStack.min_ele=val
27        
28                
29        
30
31    def pop(self) -> None:
32        # if not self.st:
33        #     return
34        # ans=self.st.pop()
35        # if self.ss and self.ss[-1]==ans:
36        #     self.ss.pop()
37        # return 
38        st=self.st
39        if not st:
40            return 
41        if st[-1]>MinStack.min_ele:
42            st.pop()
43        else:
44            MinStack.min_ele=2*MinStack.min_ele-st[-1]
45            st.pop()
46
47
48    def top(self) -> int:
49        # if not self.st:
50        #     return -1
51        # else:
52        #     return self.st[-1]
53        st=self.st
54        if not st:
55            return -1
56        if st[-1]>=MinStack.min_ele:
57            return st[-1]
58        elif st[-1]<MinStack.min_ele:
59            return MinStack.min_ele
60        
61        
62
63    def getMin(self) -> int:
64        # if not self.ss:
65        #     return -1
66        # else:
67        #     return self.ss[-1]
68        st=self.st
69        if not st:
70            return -1
71        else:
72            return MinStack.min_ele
73        
74
75
76# Your MinStack object will be instantiated and called as such:
77# obj = MinStack()
78# obj.push(val)
79# obj.pop()
80# param_3 = obj.top()
81# param_4 = obj.getMin()