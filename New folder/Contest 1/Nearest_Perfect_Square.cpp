
class Solution {
  public:
    long long nearestPerfectSquare(long long n) {
    long long int abovenumBER = ceil(sqrt(n+1)) * ceil(sqrt(n+1));
	long long int belownumBER = floor(sqrt(n-1)) * floor(sqrt(n-1));
	
	long long int difference_1 = n - abovenumBER;
	long long int difference_2 = belownumBER - n;
	
	if(difference_1 == difference_2){
		return belownumBER;
	}else if(difference_1 > difference_2){
		return abovenumBER;
	}else{
		return belownumBER;
	}
    }
};