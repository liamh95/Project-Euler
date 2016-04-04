public class pal{
	public static boolean palHelp(int n, int temp){
		if(n>=0 && n<10)
			return (n==temp%10);
		if(!palHelp(n/10, temp))
			return false;
		temp /= 10;
		return (n%10==temp%10);
	}

	public static boolean isPal(int n){
		int tmp = n;
		return palHelp(n,tmp);
	}

	public static void main(String[] args){
		int test = 1001;
		System.out.println(test + ": " + isPal(test));
	}
}