import java.io.* ;
import java.net.* ;
import java.util.Scanner;

class Servidor {
	static final int PUERTO=5000;
	String entradaTeclado = "";
	public Servidor( ) {
		try {
			ServerSocket skServidor = new ServerSocket( PUERTO );
			Scanner entradaEscaner = new Scanner (System.in);
			
			System.out.println("Esperando conexión... (Pulse 0 para salir)" );
			System.out.println("Conectado" );
			System.out.println("Empiezas a hablar tu" );
			for (int numCli=0;numCli<2;numCli++){
				Socket skCliente = skServidor.accept();
				
				InputStream aux2 = skCliente.getInputStream();
				OutputStream aux = skCliente.getOutputStream();
				
				DataOutputStream flujo= new DataOutputStream( aux );
				DataInputStream flujo2 = new DataInputStream( aux2 );
				
				do{
					entradaTeclado = entradaEscaner.nextLine ();
					flujo.writeUTF(entradaTeclado );
					System.out.println("Cliente: "+  flujo2.readUTF() );
				}while(entradaTeclado!="0");

				skCliente.close();
			}
			System.out.println("Cerrando conexión");
		} catch( Exception e ) {
			System.out.println( e.getMessage() );
		}
	}
	
	public static void main( String[] arg ) {
		new Servidor();
	}
}