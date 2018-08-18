binary_search(int arr[], int n){ // F....FFFTTTTT....T //we want to find the first true
	int l = 0, int r = n-1;
	int mid;
	
	while(l<=r){
		if(P(mid)==false){ //for case of T.......TTTTTFFFFF......F  , replace false with true and finally output value at l-1 (which will be the last true value)
			l= mid + 1;
		}else{
			r = mid;  //since the current true value may be the first True value and l should be able to reach it
		}
	}
	
	if(p(l)) return arr[l]; 
}
