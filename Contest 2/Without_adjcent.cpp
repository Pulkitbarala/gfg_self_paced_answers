//User function Template for C++

long long FindMaxSum(long long arr[], int n) 
{
   long long inclUDE = arr[0];
	    long long exclUDE = 0;
	    long long new_excl;
	    
	    for(int i=1; i<n; i++){
	        
	        new_excl = (inclUDE > exclUDE) ? inclUDE : exclUDE;
	        
	        inclUDE = exclUDE  + arr[i];
	        exclUDE =  new_excl;
	    }
	    
	   // cout<<((inclUDE > exclUDE) ? inclUDE : exclUDE)<<endl;
	   if(inclUDE > exclUDE){
	       return inclUDE;
	   }else{
	       return exclUDE;
	   } //Your code here
}