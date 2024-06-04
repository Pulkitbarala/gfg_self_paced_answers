 

class Solution{
    public:
    
    // X[], Y[]: input array
    // M, N: size of arrays X[] and Y[] respectively
    //Function to count number of pairs such that x^y is greater than y^x.
    long long countPairs(int X[], int Y[], int M, int N)
    {
	long long ans = 0; 

	for (int i = 0; i < M; i++) 
		for (int j = 0; j < N; j++) 
			if (pow(X[i], Y[j]) > pow(Y[j], X[i])) 
				ans++; 
	return ans; 
}

};

//Not optimized will be updated soon