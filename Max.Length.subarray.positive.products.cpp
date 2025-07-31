#include<iostream> 
#include<vector> 

using namespace std; 

class Solution{
public: 
     int getMaxLen(vector<int>& nums) {
       int posLength =0; 
       int negLength =0; 
       int maxLength =0; 
       for(int n: nums){
         if(n==0){
           posLength =0; 
           negLength =0; 
         }else if(n>0){
           ++posLength; 
           negLength = (negLength>0)? ++negLength : 0; 
         }else {
           int temp = posLength; 
           posLength = (negLength>0) ? ++negLength :0; 
           negLength = temp+1; 
         }
         maxLength = max(maxLength, posLength); 
       }
       return maxLength; 
     }
};
int main(){
  vector<int> nums = {0,1,-2,-3,-4}; 
  Solution sol; 
  cout << sol.getMaxLen(nums) << endl; 
  return 0; 
}
