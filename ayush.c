#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
string rearrangeString(string S) {
    int n = S.size();
    unordered_map<char, int> freq;
    for (char c : S) {
        freq[c]++;
    }

    for (auto &entry : freq) {
        if (entry.second > (n + 1) / 2) {
            return "impossible";
        }
    }

    sort(S.begin(), S.end());

    vector<char> result(n);
    int mid = (n + 1) / 2;
    

    int idx = 0;
    for (int i = 0; i < mid; i++) {
        result[i] = S[idx++];
    }
    for (int i = mid; i < n; i++) {
        result[i] = S[idx++];
    }
    

    for (int i = 0; i < mid; i++) {
        if (result[i] == result[n - i - 1]) {
 
            if (i + 1 < mid) {
                swap(result[i], result[i + 1]);
            } else {
                return "impossible";
            }
        }
    }
    
   
    return string(result.begin(), result.end());
}

int main() {
    string S;
    cin >> S;
    cout << rearrangeString(S) << endl;
    return 0;
}
