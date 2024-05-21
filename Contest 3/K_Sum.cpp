long long kSum(int a[],int n, int k)
{
    sort(a,a + n);
	  
	  long long sum = 0;
	  for(int i=0; i<k ;i++){
	      sum += a[i];
	  }
	  
	  return sum;
}