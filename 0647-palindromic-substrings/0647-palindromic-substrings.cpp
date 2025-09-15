class Solution {
public:
    bool isPalindrome(string s,int i,int j){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    int countSubstrings(string s) {
        int count=0; int n=s.size();
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(isPalindrome(s,i,j)) count++;
            }
        }
        return count;
        // for(int center=0;center<2*n-1;center++){
        //     int left=center/2;
        //     int right=left+center%2;
        //     while(left>=0 && right<n && s[left]==s[right]){
        //         count++;
        //         left--;
        //         right++;
        //     }
        // }
        // return count;
    }
};
// Every palindrome has a center.
// There are 2n - 1 centers in a string of length n (each character and between characters).
// Expand outward from each center to count all palindromic substrings.