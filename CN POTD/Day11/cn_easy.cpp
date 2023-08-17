#include <bits/stdc++.h>
using namespace std;

struct Result {
    int perfectHits;
    int pseudoHits;
};

int slotScore(string &original, string &guess) {
    Result result = {0, 0};
    unordered_map<char, int> freqOriginal;
    unordered_map<char, int> freqGuess;
    
    for (int i = 0; i < 4; i++) {
        freqOriginal[original[i]]++;
        freqGuess[guess[i]]++;
    }

    for (int i = 0; i < 4; i++) {
        if (original[i] == guess[i]) {
            result.perfectHits++;
            freqOriginal[original[i]]--;
            freqGuess[guess[i]]--;
        }
    }

    for (auto &it : freqOriginal) {
        char color = it.first;
        result.pseudoHits += min(freqOriginal[color], freqGuess[color]);
    }
    
    int totalScore = result.perfectHits * 2 + result.pseudoHits;
    return totalScore;
}
