
public class Pract_Cuenta {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Cuenta c=new Cuenta();
		Persona p1=new Persona(c,"Juan");
		Persona p2=new Persona(c,"Roberto");
		p1.start();
		p2.start();	

	}
	
	

}
