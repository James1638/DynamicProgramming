// Done July 30 2020
// Solves LeetCode problem 91, Decode Ways.
// https://leetcode.com/problems/decode-ways/
// Difficulty: Medium, correct responses 24.6%.
// Given a string of numbers, how many ways could you decode it
// as letters, where A=1 and Z=26.
// Difficulty is with deciding whether to use two numbers as one letter,
// i.e. is a 2 and a 6 an A and an F or are they a 26 and a Z?
// Other difficulty is handling zeros.
// Used dynamic programming.

class Solution {
public:
    int numDecodings(string s) {
        int slen=s.size();
        int use1=0;
        int use2=0;
        //if (slen==0) { return 0;} //not needed b/c problem said non-zero length s
        //if have just one character, only a 0 can't be decoded
        if (slen==1) { if (s[0]=='0') {return 0;} else {return 1;}}
        
        //now handle case of s has length 2
        //if the first character is a 0, can't decode it
        if (s[0]=='0') {use1=0; return 0; } else {use1=1;} 

        // Now, set up use2, which is how many ways first two chars can be decoded.
        //if second char also not zero and they make a small number like 21
        if ( s[1]!='0' && std::stoi(s.substr(0,2))<=26 ) {use2=2;}
        //if the first two characters are 10 or 20
        else if ( s[1]=='0' && std::stoi(s.substr(0,2))<=26 ) { use2=1;}
        //if the first character was a zero (shouldn't really need this)
        else if ( s[1]=='0' ) { return 0; }
        //otherwise there is just one way to decode the first two characters, e.g. '71'
        else { use2=1; }

        // All the previous was setting up use2 as a length to be used
        // for further dynamic programming. If length is 2, just return it.
        if (slen==2) { return use2; }
        
        // Now start dynamic programming. use3 is value how many ways to decode
        // string up to current char index ii. Need to keep previous two values, use1 and use2.
        // Otherwise logic is very much like the logic above for use 2...
        int use3;
        for (int ii=2; ii<slen; ii++) {
            if ( s[ii]=='0' && s[ii-1]=='0') { return 0; } //...just need this extra check.
            else if ( s[ii]!='0' && std::stoi(s.substr(ii-1,2))<=26 && s[ii-1]!='0') {use3=use2+use1;}
            else if ( s[ii]=='0' && std::stoi(s.substr(ii-1,2))<=26 ) {use3=use1;}
            else if ( s[ii]=='0' ) { return 0; }
            else { use3=use2; }
            use1=use2;
            use2=use3;
        }
        
        return use3;
    }
};

