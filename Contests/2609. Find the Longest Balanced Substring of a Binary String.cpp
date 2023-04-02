class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int as=0;
        int ind=0;
        for(int i=0; i<s.size(); i++){
            int zz=0;
            ind=i;
            while(s[ind]=='0' and ind<s.size()){
                zz++;
                ind++;
            }
            int one=0;
            while(s[ind]=='1' and ind<s.size()){
                one++;
                ind++;
            }
            as=max(as,min(zz,one));
            i=ind-1;
        }
        return as*2;
    }
};
