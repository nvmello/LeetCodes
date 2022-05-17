#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * range-based for-loop to print the contents of any vector
 */
void vecPrint(vector<int> x){
    for (int i: x)
        std::cout << i << ' ';
}

template<typename K, typename V>
void print_map(std::unordered_map<K, V> const &m)
{
    for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> umap;
        vector<int> result;

        for(int i = 0; i < nums.size(); i++){
            int key = nums[i];  //since you may not use the same element twice, the value can be the key, each is unique, no collisions
            // umap[key] = i;      //the indicies can then be placed in the hash map, the indices will be looked up by the value
            int complement = target - key;
            if (umap.count(complement))
            {
                result.push_back(i);
                result.push_back(umap[complement]);
            } else{
                umap.insert({key,i});
            } 
        }
        return result;
    }
};


int main(){
    vector<int> numList{2, 7, 11, 15} ;
    int target1 = 9;
    Solution s;
    vector<int> x;
    vecPrint(s.twoSum(numList, target1));
}



