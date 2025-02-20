double myPow(double x, long long int n) {
    if(n==0){
        return 1;
    }
    if(n < 0) {
        x = 1 / x; 
        n = -n;
    }
    if(n==1){
        return x;
    }
    else{
        double temp = myPow(x, n / 2);
        if(n%2==0){
            return temp * temp;
        }
        else{
            return temp * temp * x;
        }
    }
}

