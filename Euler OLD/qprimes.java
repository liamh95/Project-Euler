import java.lang.Math;

public class qprimes{


	public static boolean isPrime(int n){
		boolean ret=true;
		if(n<=1)
			return false;
		for(int i=2; i<=(int)Math.sqrt((double)n); i++){
			if(n%i == 0){
				ret=false;
				break;
			}
		}
		return ret;
	}

	public static int poly(int a, int b, int n){
		return (n*n) + (a*n) + b;
	}

	public static void main(String[] args){

		int max=0;
		int maxA=-9999;
		int maxB=-9999;

		for(int i=2; i<998; i++){
			if(isPrime(i)){
				for(int j= -1-i; j<1001; j++){
					int primes=1;
					boolean p=true;
					int k=1;
					while(p){
						if(isPrime(poly(j,i,k)))
							primes++;
						else
							p=false;
						k++;
					}
					if(primes>max){
						max=primes;
						maxA=j;
						maxB=i;
					}
				}
			}
		}

		System.out.println("Max a: " + maxA + "\nMax b: " + maxB + "\nMax Primes: " + max + "\nAns: " + maxA*maxB);
		System.out.println(isPrime(9));
	}
}