public class TicTac {
  public static void main(String[] args){
		Tic tic=null;
		Tac tac=null;
		tic=new Tic(1); //creo hilo
		tac=new Tac(1); //creo hilo
		tic.start();
		tac.start(); //iniciar hilo
    	
	
	} //fin main
}