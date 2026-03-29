class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1==s2){
            return true;
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(j-i==2){
                    swap(s1[i],s1[j]);
                      if(s1==s2){
                    return true;
                }
                
                    
                }
                
                
              
            }
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(j-i==2){
                    swap(s2[i],s2[j]);
                      if(s1==s2){
                    return true;
                }
                
                    
                }
            }
        }
        return false;
    }
};