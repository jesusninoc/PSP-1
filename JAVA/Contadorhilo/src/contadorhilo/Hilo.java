package contadorhilo;

public class Hilo extends Thread{

	//propiedades
	private int contador;
	
	//constructor
	Hilo (int x){
		this.contador=x;
	}
	//run	
	public void run(){
		try {
			while (true) {
				contador++;
				Thread.sleep(1000);
			}
		}catch (InterruptedException e){
			System.out.println("Ha ocurrido una excepcion");
		}
				
	}
	
	public int getcontador(){
		return contador;
	}
		
}
