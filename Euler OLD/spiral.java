public class spiral{
	public static void main(String[] args){
		int sum=0;
		for(int i=1; i<=1001; i+=2)//TR+TL
			sum += 2*(i*i) - i+1;
		int bl=0;
		for(int j=1; j<=500; j++)
			sum += (2*j*2*j)+1;

		int brtemp=1;
		for(int k=0; k<=499; k++){//BR
			brtemp += k*8+2;
			sum += brtemp;
		}
		sum--;
		System.out.println(sum);
	}
}