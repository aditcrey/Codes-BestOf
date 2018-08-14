int gcd(int a, int b){
    if(a==b) return a;
    
    if(a>b)
        return gcd(a-b,b);
    return gcd(a,b-a);
}

int lcm(int a,int b){


    return (a*b)/gcd(a,b);  //since LCM(a,b) = (a*b)/GCD(a,b)
}
