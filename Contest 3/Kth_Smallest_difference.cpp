bool pairExists(int arr[], int n, int c)
{
    unordered_set<int> s;
	    
	    bool flag = false;
	    
	    for(int i=0; i<n; i++){
	        
	        if(s.find(c^arr[i]) != s.end()){
	           flag = true;
	           break;
	        }
	        
	        s.insert(arr[i]);
	    }
	    return flag;
    //Your code here
}