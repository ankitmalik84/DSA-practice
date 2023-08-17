/* 
    Time complexity: O(1)
    Space complexity: O(1)
*/

// Helper function.
long long helper(int n, int i) {
    
    // Do shifting.
    long long temp = (n >> (i + 1)) << i;
    
    // Check whether 'ith' bit is set in 'n'.
    if ((n >> i) & 1)
        temp += (n & ((1LL << i) - 1));
        
    return temp;
}

long long optimizeCode(int a, int b, int c, int d) {
    
    // To store result.  
    long long res = 0 ; 
    
    // To store count of numbers between 'A' and 'B' and 'C' and 'D'.
    long long num0 = b - a + 1;
    long long num1 = d - c + 1;
    
    // Iterate the bits.
    for(int i = 0; i < 31; i++){
        
        // To store counts.
        long long s0 = helper(b + 1, i) - helper(a, i);
        long long s1 = helper(d + 1, i) - helper(c, i);
        
        // (Set * Unset).
        res += ((1LL << i) * ((s0 * (num1 - s1)) % 1000000007));
        res %= 1000000007;
        
	// (Unset * Set).
        res += ((1LL << i) * (((num0 - s0) * s1) % 1000000007));
        res %= 1000000007;
    }
    
    return res; 
}