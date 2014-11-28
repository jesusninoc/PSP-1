import java.io.*;
import java.util.Scanner;

public class Ejemplo1{
public static void main(String[] args) {
	Runtime r=Runtime.getRuntime();
	String comando;
	System.out.println("Introduce el comando");
	Scanner johansson = new Scanner(System.in);
	comando = johansson.nextLine();
	johansson.close();
	Process p;

	try{
		p=r.exec(comando);
		} catch(Exception e) {
			System.out.println ("Error en "+comando);
			e.printStackTrace();
			}
	}

}//Ejemplo1
