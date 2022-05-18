#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/**
 * range-based for-loop to print the contents of any vector
 */
void vecPrint(vector<int> x){
    for (auto i: x)
        std::cout << i << ' ';
}

template<typename K, typename V>
void print_map(std::unordered_map<K, V> const &m)
{
    for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
    cout<<endl;
}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        unordered_map<char, int> umap; //unordered map to store unique chars
        vector<int> result;

        for (int i = 0; i < s.length(); i++)
        {
            // print_map(umap);     //test code to see what is in map

            if(umap.count(s[i])){       //if a character is in the hash map
                result.push_back(len);  //push the current length to result length vector
                umap.clear();           // clear the hash map for a new substring
                umap[s[i]];             //push the current char into the hash map
                len = 1;                //set the new len to 1
            } 
            else{                       //if the current char is not in the hash map
                umap[s[i]] = i;             //add it to the hash map
                len++;                  //increase the length by 1
            }
        }
        result.push_back(len);  //pushes final substring to the result length vector

        // vecPrint(result);    //test code to see the length vector 

        auto ans = *max_element(result.begin(), result.end());  //pull the largest length from length vector
        return ans;
    }
};




int main(){
    Solution x;
    cout<<x.lengthOfLongestSubstring("Hello")<<endl;
}