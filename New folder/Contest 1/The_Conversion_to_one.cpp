long long minOperations(long long n)
{
    if(n == 1){
		return 0;
	}
	
	else if(n%2 == 0){
		return 1 + minOperations(n/2);
	}else{
		return 1 + min(minOperations(n-1),minOperations(n+1));
	}//Your code here
}