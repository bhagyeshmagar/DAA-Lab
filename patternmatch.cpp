#include <iostream>
#include <string>
using namespace std;

void search(string& pat, string& txt) {
    int M = pat.size();
    int N = txt.size();

    // A loop to slide pat[] one by one
    for (int i = 0; i <= N - M; i++) {
        int j;

        // For current index i, check for pattern match
        for (j = 0; j < M; j++) {
            if (txt[i + j] != pat[j]) 
           {
                break;
            }
        }

        // If pattern matches at index i
        if (j == M) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

// Driver's Code
int main() {
  string pattern, text;
  cin >> pattern >> text;
    search(pattern, text);
    
    return 0;
}
//taking input from user 