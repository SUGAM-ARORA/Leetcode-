class Solution {
public:
    int distMoney(int money, int children) {
        if(money<children) return -1;
        if(money<8) return 0;
        int d=money/8;
        int md=money%8;
        if(d==children and md==0) return children;
        if(d>=children) return children-1;
        if(md==4 and (children-d)==1) return children-2;
        if(md>=(children-d)) return d;
        int left=children-d;
        while(md<left){
            left++;
            md+=8;
            d--;
        }
        return d;
        
    }
};
