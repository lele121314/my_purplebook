package t1076;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main().run();
	}
	void run(){
		Scanner fin= new Scanner(System.in);
		while(fin.hasNext()){
			int n=fin.nextInt();
			BigInteger ans=new BigInteger("1");
			for(int i=1;i<=n;i++){
				String x=new Integer(i).toString();
			
				ans=ans.multiply(new BigInteger(x));
			}
			System.out.println(ans.toString());
		}
	}
}
