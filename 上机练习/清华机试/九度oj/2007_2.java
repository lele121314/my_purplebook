package t1080;

import java.math.BigInteger;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main().run();
	}
	void run(){
		Scanner fin=new Scanner(System.in);
		while(fin.hasNext()){
			BigInteger a=new BigInteger(fin.next());
			String x=a.toString(2);
			String ans=new String();
			for(int i=0;i<x.length();i++){
				ans+=x.charAt(x.length()-1-i);
			}
			BigInteger b=new BigInteger(ans,2);
			System.out.println(b.toString(10));
		}
	}

}
