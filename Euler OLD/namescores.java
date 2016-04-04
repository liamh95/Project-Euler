import java.util.*;
import java.io.*;
public class namescores{

	public static int score(int pos, String name){
		int ret=0;
		for(int i=0; i<name.length(); i++){
			ret += name.charAt(i)-96;
		}
		return pos*ret;
	}

	public static void main(String[] args) throws FileNotFoundException{
		ArrayList<String> names = new ArrayList<String>();		
		try{
			Scanner in = new Scanner(new FileReader("names.txt"));
			while(in.hasNextLine()){
				names.add((String)in.nextLine().toLowerCase());
			}
			Collections.sort(names);
			int total=0;
			for(int i=0; i<names.size(); i++)
				total += score(i+1,names.get(i));
			System.out.println(total);
		}
		catch(FileNotFoundException e){
			System.out.println("lel");
		}
	}
}