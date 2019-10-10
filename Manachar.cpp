#include <bits/stdc++.h>

const int N =  100000 + 1;

using namespace std;

int P[N * 2];

// Transform S into new string with special characters inserted.
string convertToNewString(const string &s)
{

    string newString = "@"; // @ for avoiding bound checking

    for (int i = 0; i < s.size(); i++) {
        newString += "#" + s.substr(i, 1);
    }

    newString += "#$"; // $ for avoiding bound checking
    return newString;
}

string longestPalindromeSubstring(const string &s)
{

    string Q = convertToNewString(s);
    int c = 0, r = 0;  // current center, right limit

    for (int i = 1; i < Q.size() - 1; i++) { //no boundaries
        // find the corresponding letter in the palidrome subString
        int iMirror = c - (i - c);

        if(r > i) {
            P[i] = min(r - i, P[iMirror]);
        }

        // expanding around center i
        while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){
            P[i]++;
        }

        // Update c,r in case if the palindrome centered at i expands past r,
        if (i + P[i] > r) {
            c = i;              // next center = i
            r = i + P[i];
        }
    }

    // Find the longest palindrome length in p.

    int maxPalindrome = 0;
    int centerIndex = 0;

    for (int i = 1; i < Q.size() - 1; i++) {

        if (P[i] > maxPalindrome) {
            maxPalindrome = P[i];
            centerIndex = i;
        }
    }

    //cout << maxPalindrome << "\n";
    return s.substr( (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
}

//Print the length of the longest palindrome substring in the first line. In the second line print the longest palindromic substring in S.
// If there is more than one palindromic substring with the maximum length, output the first one.
int main() 
{
    string s;
    cin >> s;
    cout << longestPalindromeSubstring(s).size() << "\n" << longestPalindromeSubstring(s);
    return 0;
}
