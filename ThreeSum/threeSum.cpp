#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void printVec(vector<vector<int> > v1){
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v1[i].size(); j++)
        {
            cout<< v1[i][j] << " " ;
        }
    }
}

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > v1{{1,2,3}, {2,4,6}};
        // printVec(v1);
        return v1;
    }
};

int main(){
    vector<int> v{1,3,5};
    Solution s;
    s.threeSum(v);
    cout<<"\nSetup complete"<<endl;
}