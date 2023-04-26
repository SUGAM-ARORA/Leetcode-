method 1 
  
  
  class Solution {
public:
    int addDigits(int num) {
      int sum=0;
        while(num)
        {
            sum+=(num%10);
            num/=10;
        }
        if(sum<10)
            return sum;
        else
            return addDigits(sum);
    }
};





method 2 
  
  
  
  
  class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        else if(num % 9 == 0) return 9;
        else return num % 9;
    }
};







method  3
  
  
  
  class Solution {
public:
    int addDigits(int num) { return  1 + (num - 1) % 9; }
};
