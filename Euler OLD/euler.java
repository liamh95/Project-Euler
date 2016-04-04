class Triple{
	int a;
	int b;
	int c;

	public Triple(int m, int n){
		a=m*m - n*n;
		b = 2*m*n;
		c = m*m + n*n;
	}

}

public class euler{
	public static int answer(){
		for(int m=2; m<1000; m++){
			for(int n=1; n<m; n++){
				Triple test = new Triple(m,n);
				if(test.a + test.b + test.c ==1000)
					return test.a*test.b*test.c;
			}
		}
		return -1;
	}

	public static void main(String[] args){
		System.out.println(answer());
	}
}