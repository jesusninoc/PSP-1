public class Tic extends Thread {
	
	//Propiedades --------------------------------
	private int hilo;

	//Constructor --------------------------------
	public Tic (int hilo){
		this.hilo=hilo;
	}//fin constructor
	
	//Método Run -----------------------------------
	public void run(){
		while (true){
			System.out.println ("TIC");
			//sleep(1000);
			try {		
			// Pause for 4 seconds
         	this.sleep(2000);
			 } catch (InterruptedException e) {
                          }
			
		}
	}//fin run
	
}