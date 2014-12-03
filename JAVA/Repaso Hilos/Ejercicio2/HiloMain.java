
public class HiloMain {
	
	public static void main(String args[]){
		RepasoHilos2 rH1 = new RepasoHilos2(1,2,1,1);
		RepasoHilos2 rH2 = new RepasoHilos2(10,11,1,1);
		RepasoHilos2 rH3 = new RepasoHilos2(20,30,1,1);
		rH1.start();
		rH2.start();
		rH3.start();
		while(true){
			System.out.println("Hilo 1:");
			rH1.MostrarValores();
			System.out.println("Hilo 2:");
			rH2.MostrarValores();
			System.out.println("Hilo 3:");
			rH3.MostrarValores();
			try{
				Thread.sleep(1000);
			}catch (InterruptedException e){e.printStackTrace();}
		}
	}
	
}
