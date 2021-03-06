public class pandig{
	public static void main(String[] args){
		int i;
		int sum=0;
		int[] digs = {0,0,0,0,0,0,0,0,0,0};
		int[] prods=new int[9999];
		for(i=0; i<9999; i++)
			prods[i]=0;
		for(i=100; i<=999; i++){
			int j=10;
			//multiplications
			while(i*j<=9999){
				//reset digits
				int k;
				for(k=0; k<10; k++)
					digs[k]=0;
				int prod = i*j;
				prods[prod-1]++;
				int it=i;
				int jt=j;
				//check digits
				while(it>0){
					digs[it%10]++;
					it /= 10;
				}
				while(jt>0){
					digs[jt%10]++;
					jt /= 10;
				}
				while(prod>0){
					digs[prod%10]++;
					prod /= 10;
				}
				k=1;
				while(k<10 && digs[k]==1){
					k++;
				}
				sum += (k==10 && prods[i*j-1]==1) ? i*j : 0;
				j++;
			}
		}
		System.out.println(sum);
	}
}