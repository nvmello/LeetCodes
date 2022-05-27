#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * More efficient rework of previous algorithm, O(n) time complexity because starting at either end of the vector
     * and meeting in the middle allows us to traverse the vector only once
     */
    int maxArea(vector<int>& height) {
        int temp = 0;           //temp var for comparing each interations volume with the current max volume
        int maxVol = 0;         //max volume to be returned
        int l = 0;              //value beginning on the left hand side of the vector
        int r= height.size()-1; //value beginning on the right hand side of the vector

        while (l < r)   //while the left point is smaller than the right point
        {
            // cout<<height[l] << " : " << height[r] << endl;
            temp = min(height[l], height[r]) * (r-l);   //set the temp value to the most recently calculated volume
            if (temp > maxVol)                      //compare to the current max value
            {
                maxVol = temp;                      // reset max value if a new max is found
            }
            // cout<<" l = " << l << " r = " << r << endl;
            // cout<<temp<<endl;
            if (height[l] <=  height[r])    //if the left side is smaller than the right
            {
                l++;                            // move the left side right one place
            } else{
                r--;                            //otherwise move the right side left one place
            } 
        }
        
       return maxVol;
    }
};

int main(){
    Solution x;
    vector<int> v {1,8,6,2,5,4,8,3,7};
    cout<<x.maxArea(v)<<endl;
}