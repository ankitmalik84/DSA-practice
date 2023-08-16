#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<double> sampleStats(vector<int> &count)
{
    vector<double> result;
    int n = count.size();
    
    double sum = 0;
    int totalNums = 0;
    int minNum = -1;
    int maxNum = -1;
    int maxFreq = 0;
    int mostFrequent = -1;

    for (int i = 0; i < n; i++) {
        if (count[i] > 0) {
            if (minNum == -1) {
                minNum = i;
            }
            maxNum = i;
            
            sum += i * count[i];
            totalNums += count[i];
            
            if (count[i] > maxFreq) {
                maxFreq = count[i];
                mostFrequent = i;
            }
        }
    }
    
    double mean = sum / totalNums;
    result.push_back(static_cast<double>(minNum));
    result.push_back(static_cast<double>(maxNum));
    result.push_back(mean);
    
    int mid = totalNums / 2;
    double median = 0.0;
    int freqSoFar = 0;
    for (int i = 0; i < n; i++) {
        if (count[i] > 0) {
            freqSoFar += count[i];
            if (totalNums % 2 == 1 && freqSoFar > mid) {
                median = i;
                break;
            } else if (totalNums % 2 == 0 && freqSoFar >= mid) {
                if (freqSoFar == mid) {
                    int j = i + 1;
                    while (count[j] == 0) {
                        j++;
                    }
                    median = (i + j) / 2.0;
                } else {
                    median = i;
                }
                break;
            }
        }
    }
    result.push_back(median);
    result.push_back(static_cast<double>(mostFrequent));

    return result;
}

