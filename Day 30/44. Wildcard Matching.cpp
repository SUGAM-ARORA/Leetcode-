class Solution {
public:
    bool isMatch(string s, string p) {
    int n=s.length();
        int m=p.length();
        bool res[m+1][n+1];
        memset(res,false,sizeof(res));
        res[0][0]=true;
        for(int i=1;i<=m;i++){
            if(p[i-1]=='*'){
                res[i][0]=res[i-1][0];
            }
            for(int j=1;j<=n;j++){
                if(p[i-1]=='*'){
                    res[i][j]=res[i-1][j]||res[i][j-1];
                }
                else if(p[i-1]==s[j-1]||'?'==p[i-1]){
                    res[i][j]=res[i-1][j-1];
                }
            }
        }
        return res[m][n];
    }   
};
