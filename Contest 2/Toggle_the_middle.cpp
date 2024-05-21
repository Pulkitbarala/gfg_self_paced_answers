//User function Template for C++

int toggleTheMiddle(int n)
{
    if(n == 1){
	        return 0;
	    }else if(n == 0){
	        return 1;
	    }else{
	        int NumberOfBits = floor(log(n)/log(2)) + 1;
	        
	        if(!(NumberOfBits % 2)){
	            int Middle = NumberOfBits/2;
	            int before_Middle = Middle - 1;
	            
	            n = (n ^ (1 << (Middle)));
	            n = (n ^ (1 << (before_Middle)));
	            
	            return n;
	        }else{
	            //shift the middle bit only
	            int Middle = NumberOfBits/2;
	            n = (n ^ (1 << (Middle)));
	            return n;
	        }
	    }
}