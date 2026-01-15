class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        
        // intake => ceil(quotient)
        // for one k, hours = summation of ceil(piles[i] / k)
        // within h hours, so summation <= h
        // at largest k, min value of h = total piles
        // at smallest k, max value of h = summation of all pile sizes
        // if summation > h, inc k -> like 
        // if summation <= h, dec k -> like 
        int smallest = 1;
        int largest = * max_element(piles.begin(),piles.end());
        
        while (smallest<largest)
        {
            int k = smallest + (largest-smallest)/2;
            int total = 0;
            for (int i:piles)
            {
                total+=(i + k - 1) / k;
            }
            if (total>h)
            {
                smallest = k+1;
            }
            else largest = k;
        }
        return smallest;
    }
};
