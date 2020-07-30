// Done July 29 2020
// Solves LeetCode problem 5, Longest Palindromic Substring.
// https://leetcode.com/problems/longest-palindromic-substring/
// Difficulty Medium, success rate 29.4%.
// Problem is just like it sounds, find the longest palindromic substring 
// of a string.
// Use dynamic programming. For string of length n, have 2*n-1 possible starts
// of a palindrome. The n letters and the n-1 combinations of two successive letters.
// For each of those cases, if it is a palindrome, add a letter before and after
// and see if you have a longer palindrome. Keep track of the longest one.
// I imagined this as going along diagonals in a matrix where the main diagonal
// was one letter long and every element of the matrix off the main diagonal
// added letters before and after. So checking palindromes was like going away
// from the main diagonal towards the upper-right corner of the matrix.

class Solution {
public:
    string longestPalindrome(string s) {
        int slen = s.size();
        if ( slen==0 ) { return ""; }
        int diags[2*slen-1];
        for (int ii=0; ii<2*slen-1; ii++) {  diags[ii]=1; }
        int maxlen=1;
        int addodd=1;
        int addeven=1;
        int gap=1;
        int mbeg=0;
        int mgap=0;
        while ( gap<slen && ( addodd==1 || addeven==1 ) ) {
            if (gap%2==1) { addodd=0; } else { addeven==0; }
            for (int ii=0; ii<slen-gap; ii++) {
                if ( s.at(ii)==s.at(ii+gap) && diags[gap+2*ii+1]==1) { 
                    if (gap%2==1) { addodd=1; } else { addeven==1; }
                    mbeg=ii; 
                    mgap=gap; 
                } else { diags[gap+2*ii+1]=0; }
            }
            if ( ( gap%2==1 && addodd==1 ) || ( gap%2==0 && addeven==1 )  ) { maxlen++; }
            gap++;
        }
        return s.substr(mbeg,mgap+1);
    }
};

