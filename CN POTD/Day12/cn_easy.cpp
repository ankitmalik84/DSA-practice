#include <bits/stdc++.h> 
bool checkBits(unsigned int n) {
    if(n==0) return false;
    int prevBit = n&1;
    n>>=1;
    while(n){
        int currentBit= n&1;
        if(currentBit==prevBit) return false;

        prevBit = currentBit;
        n>>=1;
    }
    return true;
}