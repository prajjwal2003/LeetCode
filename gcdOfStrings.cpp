// x would be something that str1 as well as str2 would be the multiples of x.
// 1. if x is like that, str1 + str2 would be same as str2 + str1
// EX: str1 = abab and str2 = ababab
// here x = ab and str1 = 2x and str2 = 3x
// now our x would be the gcd of 2 and 3 in the above case.
// but since we don't know what x exactly is, we take gcd of the lengths of both strings.
// so length of x = l = gcd of str1 and str2
// for making x, just take a substring of any string starting from 0th index with size 'l'...
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1){
            return "";
        }
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};