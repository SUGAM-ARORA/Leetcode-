class Solution {
public:
    string defangIPaddr(string s) {
        queue<char> s1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='.'){
                s1.push('[');
                s1.push(s[i]);
                s1.push(']');
            }else{
                s1.push(s[i]);
            }
        }
        string st;
        while(!s1.empty()){
            st+=s1.front();
            s1.pop();
        }
        return st;
    }
};
