class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        long res = (long)dividend / (long)divisor;
        return lround(res);
    }
};
