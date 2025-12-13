//O(1),O(1)

// User function Template for C++

class Solution {
  public:
    int countNodes(int i) {
        // your code here
        return pow(2,i-1);
    }
};

//O(1),O(1)

class Solution {
  public:
    int countNodes(int i) {
        return 1 << (i - 1);
    }
};
