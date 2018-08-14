
int gcd_(int a,int b){
    if(a==b) return a;
    return gcd(b%a,a);
}
