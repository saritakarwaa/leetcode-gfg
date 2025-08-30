class Solution {
public:
    int sumofSquares(int n){
        int sum=0;
        while (n>0) {
            int digit = n % 10; // Get the last digit
            sum+=digit*digit;
            n /= 10; // Remove the last digit
        }
        return sum;
    }
    bool isHappy(int n) {
    //    while(n!=1 && n!=4){
    //         n=sumofSquares(n);
    //    }
    //    return n==1;
        int slow=n,fast=n;
        do{
            slow=sumofSquares(slow);
            fast=sumofSquares(sumofSquares(fast));
        }while(slow!=fast);
        return slow==1;
    }
};

// n == 1 → Happy number ✅
// n == 4 → Cycle detected ❌