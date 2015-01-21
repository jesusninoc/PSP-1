import java.io.* ;
import java.net.* ;
import java.util.Scanner;

class Servidor {
	static final int PUERTO=5000;
	String entradaTeclado = "";
	int asientos;
	int asientosGal = 8;
	int asientosLat1 = 4;
	int asientosLat2 = 4;
	int asientosCent = 54;
	
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
					/*System.out.println("*Menu teatro*");
					System.out.println("Tipos de asisntos disponibles:");
					System.out.println("Gal(150€) "+ asientosGal + " disponibles");
					System.out.println("Lat1 (100€) "+ asientosLat1 + " disponibles");
					System.out.println("Lat2 (100€) "+ asientosLat2 + " disponibles");
					System.out.println("Cent (80€) "+ asientosCent + " disponibles");
					System.out.println("");
					System.out.println("Que zona quiere");*/
					
					String menu = "*Menu teatro* \n" +
							"Tipos de asisntos disponibles: \n" +
							"Gal(150€) "+ asientosGal + " disponibles \n" +
							"Lat1 (100€) "+ asientosLat1 + " disponibles \n" +
							"Lat2 (100€) "+ asientosLat2 + " disponibles \n" +
							"Cent (80€) "+ asientosCent + " disponibles \n" +
							"\n" +
							"Que zona quiere? \n";
					
					//entradaTeclado = entradaEscaner.nextLine ();
					flujo.writeUTF(menu);
					entradaTeclado =  flujo2.readUTF();
					if(entradaTeclado != "0"){
						System.out.println("Cliente:"+entradaTeclado);
						switch(entradaTeclado) {
							case "Gal":
								//System.out.println("Entradas reservadas");
								flujo.writeUTF("Indique el numero de entradas que quiere");
								asientos =  Integer.parseInt(flujo2.readUTF());
								System.out.println("Cliente:"+asientos);
								if(asientosGal >= asientos){
									asientosGal = asientosGal-asientos;
									flujo.writeUTF("Compra realizada correctamente");
								}else{
									flujo.writeUTF("No hay tantas entradas disponibles");
								}
								break;
								
							case "Lat1":
								flujo.writeUTF("Indique el numero de entradas que quiere");
								asientos =  Integer.parseInt(flujo2.readUTF());
								System.out.println("Cliente:"+asientos);
								if(asientosLat1 >= asientos){
									asientosLat1 = asientosLat1-asientos;
									flujo.writeUTF("Compra realizada correctamente");
								}else{
									flujo.writeUTF("No hay tantas entradas disponibles");
								}
								break;
								
							case "Lat2":
								flujo.writeUTF("Indique el numero de entradas que quiere");
								asientos =  Integer.parseInt(flujo2.readUTF());
								System.out.println("Cliente:"+asientos);
								if(asientosLat2 >= asientos){
									asientosLat2 = asientosLat2-asientos;
									flujo.writeUTF("Compra realizada correctamente");
								}else{
									flujo.writeUTF("No hay tantas entradas disponibles");
								}
								break;
								
							case "Cent":
								flujo.writeUTF("Indique el numero de entradas que quiere");
								asientos =  Integer.parseInt(flujo2.readUTF());
								System.out.println("Cliente:"+asientos);
								if(asientosCent >= asientos){
									asientosCent = asientosCent-asientos;
									flujo.writeUTF("Compra realizada correctamente");
								}else{
									flujo.writeUTF("No hay tantas entradas disponibles");
								}
								break;
						}
					}
					
					//System.out.println("Cliente: "+  flujo2.readUTF() );
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