#include<iostream>
#include <vector>
// #include <algorithm>
// #include <unordered_map>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string temp ;

        return temp;
    }

    string isPalindrome(string s) {
        bool flag = true;
        int len = s.length();
        for (int i = 0; i < s.length(); i++)
        {
            
            if (s[i] == s[s.length()-1-i])
            {
                flag = true;
                cout<<s[i] << " : " << s[len-1-i] << " = " << flag <<endl;
            } else{
                flag = false;
                cout<<s[i] << " : " << s[len-1-i] << " = " << flag <<endl;
                break;
            }
        }
        cout<<flag<<endl;
        return s;
    }

    string isPalindromeMid(string s) {
        if (s.length() < 2 )
        {
            return "N/A";
        }
        else{
            if (s.length() % 2 == 0)    //if the string length is even
            {
                /* code */
            } 
            else{                     //if the string length is odd
                int mid = s.length()/2;   //dividing odd int number by 2 results in a decimal value, cpp rounds this value up to the nearest int
                int l = mid;
                int r = mid;
                for (int i = 0; i < mid; i++)
                {
                    if (s[l-1] == s[r+1])
                    {
                        cout<< s[l-1] << " : " << s[r+1] << endl;
                        //probably save all palindromes in a vector or something here
                        l--;
                        r++;
                    }
                    
                }
                
            }
            
        }
        
        return s;
    }
};

int main(){
    Solution x;
    // cout<<x.isPalindrome("cabababac")<<endl;       //babad should return either 'bab' or 'aba'
    cout<<x.isPalindromeMid("sxbatabxs")<<endl;       //babad should return either 'bab' or 'aba'
}