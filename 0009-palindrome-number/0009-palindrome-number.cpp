class Solution {
public:
    bool isPalindrome(int x) {
        int temp=x;
        long long res=0;
        while(x>0)
        {
            res=(res*10)+(x%10);
                x=x/10;
        }
        if(temp==res)
            return true;
        else
            return false;
    }
};