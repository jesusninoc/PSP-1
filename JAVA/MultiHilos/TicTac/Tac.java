public class Tac extends Thread {
	
	//Propiedades --------------------------------
	private int hilo;

	//Constructor --------------------------------
	public Tac (int hilo){
		this.hilo=hilo;
	}//fin constructor
	
	//Método Run -----------------------------------
	public void run(){
		try{
			sleep(1000);
		} catch (InterruptedException e) {
                          }
		while (true){
				System.out.println ("TAC");
			try {		
			// Pause for 4 seconds
         	this.sleep(2000);
			 } catch (InterruptedException e) {
                          }
		
			//sleep(1000);
		}
	}//fin run
	
}