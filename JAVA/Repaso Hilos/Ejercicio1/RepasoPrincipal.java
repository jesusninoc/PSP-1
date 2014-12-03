
public class RepasoPrincipal {
	
	public static void main(String args[]){
		RepasoHilos1 rH1 = new RepasoHilos1(1,2,1,1);
		rH1.start();
		while(true){
			rH1.MostrarValores();
			try{
				Thread.sleep(1000);
			}catch (InterruptedException e){e.printStackTrace();}
		}
	}

}
