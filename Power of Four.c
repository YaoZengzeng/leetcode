bool isPowerOfFour(int num) {
    int n = 1, i;
    for (i = 0; i< 16; i++) {
        if (num == n) {
            return true;
        }
        
        n *= 4;
    }
    
    return false;
}
