import java.util.Random;


public class Persona extends Thread{
	private Cuenta c;
	private String nombre;
	
	public Persona (Cuenta c,String nombre){
		this.c = c;
		this.nombre=nombre;
	}
	
	public void run(){
		//2 ingresos
		//2 reitegros
		
		Random r = new Random();
		int ingreso = r.nextInt(500)+1;
		System.out.println(nombre+" ingresa "+ ingreso);
		
		c.put(ingreso);
		
		String saldoactual = c.obtenerSaldo();
		System.out.println(saldoactual);
		
		Random r2 = new Random();
		int reintegro = r2.nextInt(500)+1;
		System.out.println(nombre+" retira "+ reintegro);
		c.get(reintegro);
		
		saldoactual = c.obtenerSaldo();
		System.out.println(saldoactual);
		
		/*try {
			sleep(100);
		}catch (InterruptedException e){}
		*/
		
		
		
	}

}
