class Solution {
    public double myPow(double x, int n) {
        
        // Convert n to long to handle Integer.MIN_VALUE
        long power = n;
        
        // If power is negative, invert x
        if (power < 0) {
            x = 1 / x;
            power = -power;
        }
        
        double result = 1.0;
        
        while (power > 0) {
            // If power is odd, multiply result with x
            if (power % 2 == 1) {
                result *= x;
            }
            
            // Square x
            x *= x;
            
            // Divide power by 2
            power /= 2;
        }
        
        return result;
    }
}
