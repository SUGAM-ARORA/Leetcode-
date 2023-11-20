#pragma GCC optimize("O3")
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) 
    {
        const int n=garbage.size();
        const char* GPM="GPM";
        int time=0, t[3]={0}; 
        #pragma unroll
        for(int i=n-1; i>=0; i--){//time for collecting garbage
            string x=garbage[i];
            time+=x.size();
            #pragma unroll
            for(int j=0; j<3; j++)
                if (t[j]==0 && x.find(GPM[j])!=-1) t[j]=i;
           
        }
        sort(t, t+3);
        // Add travel time
        time+=3*accumulate(travel.begin(), travel.begin()+t[0],0)
            +2*accumulate(travel.begin()+t[0], travel.begin()+t[1],0)
            +accumulate(travel.begin()+t[1], travel.begin()+t[2],0);
        return time;
    }
};