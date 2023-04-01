class Solution {
public:
    int minNumber(vector<int>& n1, vector<int>& n2) 
    {
        map<int,int>mp;
        for(auto x: n1) mp[x]++;
        for(auto x: n2) mp[x]++;
        int mn1=*min_element(n1.begin(),n1.end());
        int mn2=*min_element(n2.begin(),n2.end());
        for(auto x: mp){
            if(x.second>1) return x.first;
        }
        string s;
        if(mn1<mn2) s=to_string(mn1)+ to_string(mn2);
        else s= to_string(mn2) + to_string(mn1) ;
        return stoi(s);
    }
};
