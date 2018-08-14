int gcdExtended(int a,int b, int &x, int &y){
    if(a==0){
        x = 0,y=1;
    }

    int x1, y1;
    gcdExtended(b%a, a, x1,y1);

    x = y1 - (b/a)*x1;
    y1 = x1;
}
