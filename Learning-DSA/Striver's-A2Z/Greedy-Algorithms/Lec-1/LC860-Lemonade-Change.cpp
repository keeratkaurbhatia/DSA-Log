//o(n), o(1)

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       //5 -> 0 change, 10 - > 5 change, 20 - > 15 change (5+10/5x3)
       //money store - > 5,10,20. (20 we arent concerned with in terms of change)
       
       int b5 = 0;
       int b10 = 0;
       int b20 = 0;

       for (int i : bills)
       {
        if (i==5)
        {
            b5 ++;
        }
        else if (i==10)
        {
            b10++;
            if (b5>0)
            {
                b5--;
            }
            else return false;
        }
        else
        {
            b20++;
            if (b5>0 && b10>0) //first try with 10+5 combo. 5 needed for 10's change too so we will min giving that out
            {
                b5--;
                b10--;
            }
            else if (b5>=3)
            {
                b5 -= 3;
            }
            else return false;
        }
       }
       return true;

    }
};
