class Solution {
public:
    int numOfWays(int n) {
        const int mod = 1000000007;
        long long ABA = 6;
        long long ABC = 6;
        while (n>1){
            long long oldABA = ABA;
            long long oldABC = ABC;
            ABA = ((3 * oldABA)%mod + (2 * oldABC)%mod)%mod;
            ABC = ((2 * oldABA)%mod + (2 * oldABC)%mod)%mod;
            n--;
        }
        return (ABA+ABC)%mod;
        

    }
};
