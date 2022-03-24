//
//  main.cpp
//  Compiler
//
//  Created by João Carlos Magalhães on 24/03/22.
//

//#include <bits/stdc++.h>

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> answer;
        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                if((nums[i]+nums[j])==target){
                    answer.push_back(i);
                    answer.push_back(j);
                    break;
                }
            }
        }
        return answer;
    }
};

int main() {

  //vector declaration
  vector<int> nums;
  int size, e, target;

  cout << "What is the size of the vector?" << endl;
  cin >> size;

  cout << "Input the elements of the vector" << endl;

  for(int i = 0; i < size; i++){
    cin >> e;
    nums.push_back(e);
  }

  cout << "What is the target?" << endl;
  cin >> target;

  Solution obj;
  vector<int>ans = obj.twoSum(nums, target);
  for (int i = 0; i < ans.size(); i++){
    cout << ans[i] << endl;
  }
  
  
  return 0;
    
}
