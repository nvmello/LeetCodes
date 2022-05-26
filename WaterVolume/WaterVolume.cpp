class Solution {
public:
    int maxArea(vector<int>& height) {
        
        vector<int> volume;     //Vector to hold the volumes for each pair of heights
        for(int i = 0; i < height.size(); i++){ 
            for(int j = i+1; j < height.size(); j++){   //only compare each height to every height in front of it so not to measure things twice
                
                //take the min of each height pair and mult by distance between them
                //push the product into the volumes vector
                volume.push_back(min(height[i], height[j])*(j-i));  
                
            }
        }
        // cout<<*max_element(volume.begin(), volume.end())<<endl; 
        return *max_element(volume.begin(), volume.end()); //return the max value from volumes vector
    }
};