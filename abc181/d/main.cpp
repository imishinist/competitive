#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool have_negative(vector<int> counts) {
    for (auto c : counts) {
        if (c < 0) return true;
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    vector<int> counts = vector<int>(10);
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        counts[c - '0']++;
    }

    if (s.size() == 1) {
        puts(counts[8] > 0 ? "Yes" : "No");
        return 0;
    }
    if (s.size() == 2) {
        int n = stoi(s);
        reverse(s.begin(), s.end());
        int m = stoi(s);
        puts((n % 8 == 0 || m % 8 == 0) ? "Yes" : "No");
        return 0;
    }

    for (int i = 0; i < 10; i++) {
        counts[i]--;
        for (int j = 0; j < 10; j++) {
            counts[j]--;
            for (int k = 0; k < 10; k++) {
                counts[k]--;
                int num = i * 100 + j * 10 + k;
                if (!have_negative(counts) && num % 8 == 0) {
                    puts("Yes");
                    return 0;
                }
                counts[k]++;
            }
            counts[j]++;
        }
        counts[i]++;
    }
    puts("No");

    return 0;
}
