class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res=0;
        for(int i=0;i<words.size();i++)
        {   
            int b=0;
            for( int j=0;j<pref.size();j++)
            {
                // if(words.size()<=pref.size())
                // {
                //     break;
                // }
                 if(words[i][j]!=pref[j])
                 { 
                     break;
                 }
                 else
                 {
                     b++;
                 }
            }
            if(b==pref.size())
            {
                res++;
            }
        }
        return res;
    }
};
