/*Select any subarray from the given array and flip all its elements i.e. change 0 to 1 and 1 to 0.      
After the operation find the length of largest subarray containing all 1s                                         Input :
n = 5
arr = {1,0,0,0,1}
Output:
5
Explanation:
After applying the flip operation on 
subarray {0,0,0} the array becomes 
{1,1,1,1,1}. Therefore, the largest 
possible subarray with all 1s has length 5.


Mega job-a-thon   */

class Solution {
  public:
    int toggle(int n, vector<int> &arr) {
     int start = 0, curr = 0;
        int max = 0;
        int count = 0;
        // using sliding window
        while (curr < n) {
            if (arr[curr] == 1) {
                count++;
                max = std::max(max, count);
                curr++;
            } else {
                while (curr < n && arr[curr] == 0) {
                    count++;
                    curr++;
                    max = std::max(max, count);
                }
                start = curr;
                while (curr < n && arr[curr] == 1) {
                    count++;
                    curr++;
                    max = std::max(max, count);
                }
                curr = start;
                count = 0;
            }
        }
        return max;
    }
};