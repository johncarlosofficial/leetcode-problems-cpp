class Solution {
public:
    int reverse(int x) {
        double y=0;
        while(x){
            y=y*10+x%10;
            x=x/10;
        }
        if(y>INT32_MAX || y<INT32_MIN){
            return 0;
        }
        
        return (int)y;
    }
};