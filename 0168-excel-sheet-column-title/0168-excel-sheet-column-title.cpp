class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
        string ans = "";
        while(n){
            ans = (char)(--n % 26 + 'A') + ans;
            n /= 26;
        }
        return ans;
    }
};