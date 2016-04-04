import java.lang.Math;
public class p10j{
	public static boolean isPrime(int n){
		int i=2;
		boolean ret = true;
		if(n<2)
			return false;
		if(n==2)
			return true;
		while(i<=(int)Math.sqrt((double)n) && ret){
			ret = !(n%i==0);
			i++;
		}
		return ret;
	}
	public static void main(String[] args){
		long start = System.currentTimeMillis();
		long sum = 0L;
		for(int i=2; i<2000000; i++){
			sum += (isPrime(i)) ? i : 0;
		}
		long end = System.currentTimeMillis()-start;
		System.out.println(sum + ": " + end + " ms");
	}
}