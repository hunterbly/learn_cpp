#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

// O(n^2) | O(1) Space
vector<int> method1(vector<int> array, int targetSum) {

  for(int i = 0; i < array.size() - 1; i++){
      int firstNum = array[i];
      for (int j = i + 1; j < array.size(); j++){
          int secondNum = array[j];
          if(firstNum + secondNum == targetSum){
              return firstNum > secondNum ? vector<int>{secondNum, firstNum} : vector<int>{firstNum, secondNum};
          }
      }
  }
  return {};
}

// O(n) time | O(n) space
vector<int> method2(vector<int> array, int targetSum) {

  unordered_set<int> nums;
  for (int num : array){
      int potentialMatch = targetSum - num;
      if(nums.find(potentialMatch) != nums.end()){
          return potentialMatch > num ? vector<int> {num, potentialMatch} : vector<int> {potentialMatch, num};
      } else{
          nums.insert(num);
      }

  }

  return {};
}

// O(nlog(n)) time | O(1) space
vector<int> method3(vector<int> array, int targetSum) {

  sort(array.begin(), array.end());

  int left = 0;
  int right = array.size() - 1;

  while (left < right){
      int currentSum = array[left] + array[right];
      if (currentSum == targetSum){
          return vector<int> {array[left], array[right]};
      } else if (currentSum < targetSum) {
        left++;
    } else if (currentSum > targetSum) {
        right--;
    }

  }

  return {};
}

int main(){

    vector<int> arr{ 4, 6, 1 , -3 };
    int targetSum = 3;

    vector<int> result;
    result = method3(arr, targetSum);

    for (int i = 0; i < result.size(); i++){
        cout << result[i];
        cout << "\n";
    }


    return 0;
}
