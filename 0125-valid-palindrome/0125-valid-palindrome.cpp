class Solution {
public:
    bool check(string temp){
        int i=0,j=temp.size()-1;
        while(i<j){
            if(temp[i++]!=temp[j--]){
                return false;
            }
        }
        return true;
    }
    // bool checkRecursive(string s,int left,int right){
    //     if(left>=right){
    //         return true;
    //     }
    //     return s[left]==s[right] && checkRecursive(s,left+1,right-1);
    // }
    bool isPalindrome(string s) {
        string temp="";
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                temp+=tolower(s[i]);
            }
        }
        return check(temp);
        // return checkRecursive(temp,0,temp.size()-1);
    }
};