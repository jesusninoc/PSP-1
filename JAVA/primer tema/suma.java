import java.io.*;
public class suma{
	public static void main (String[] args){
	InputStreamReader in=new InputStreamReader(System.in);
	BufferedReader br = new BufferedReader (in);
	String texto;
	
	try{
		System.out.println("Introduce un numero...");
		int s1 = Integer.parseInt(br.readLine());
		System.out.println("Introduce otro numero...");
		int s2 = Integer.parseInt(br.readLine());
		int total = s1 + s2;
		System.out.println("Total: "+total);
		in.close();
		}catch (Exception e) {e.printStackTrace();}

	}//fin main
}//fin ejemplo lectura