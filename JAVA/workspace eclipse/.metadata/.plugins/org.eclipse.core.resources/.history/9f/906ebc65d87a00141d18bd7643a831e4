
public class RepasoHilos1 extends Thread {
	
	private Thread h1;
	private int incremento1; 
	private int incremento2; 
	int contador1;
	int contador2;
	
	public RepasoHilos1(int incremento1,int incremento2,int contador1,int contador2){
		this.incremento1 = incremento1;
		this.incremento2 = incremento2;
		this.contador1 = contador1;
		this.contador2 = contador2;
		
		run();
	}
	
	public void run(){
		Thread hiloActual=Thread.currentThread();
		while(h1==hiloActual){
			contador1 += incremento1;
			contador2 += incremento2;
			try{
				Thread.sleep(1000);
			}catch (InterruptedException e){e.printStackTrace();}
			MostrarValores();
		}
	}
	
	public void MostrarValores(){
		System.out.println(contador1);
		System.out.println(contador2);
	}

}


