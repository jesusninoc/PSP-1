
public class Cuenta {

	private int numero=0;
	
	public synchronized void get(int reintegro){// Retirar saldo
		if((numero - reintegro)<0){
			System.out.println("No puedes sacar tanto dinero");
		}
		while((numero - reintegro)<=0){
			try {
				wait();
			}catch (InterruptedException e){};
		}
		numero = numero - reintegro;
		notifyAll();
		//return numero; //no hay numero 
	}

	public synchronized void put(int valor){ //Ingresar saldo
		
		notifyAll();
		numero+=valor;
		
	}
	
	public synchronized String obtenerSaldo (){ // Obtener saldo actual en la cuenta
		String saldo="";
		
		saldo = "Saldo actual "+numero+"€";
		notifyAll();
		return saldo;
	}

}
