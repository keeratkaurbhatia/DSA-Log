//O(1), O(1)

// User function Template for C++
class Solution {
  public:
    long long count(int n) {
        // your code here
        int nCtwo = (n * (n - 1)) / 2;
        long long answer = pow(2, nCtwo);
        return answer;
    }
};

