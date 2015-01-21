import java.io.* ;
import java.net.* ;
//Servidor espera conexiones a las que atenderá con un segundo socket
//Servidor saludará con frase "Hola cliente"
class Servidor {

//puerto espera conexiones
static final int PUERTO=5000;

	public Servidor( ) {

		try {
			//crea socket y espera
			ServerSocket skServidor = new ServerSocket( PUERTO );
			System.out.println("Escucho el puerto " + PUERTO );

			for (int numCli=0;numCli<3;){
				//Primitiva accept() crea nuevo socket skCliente
				//skCliente atiene al cliente
				Socket skCliente = skServidor.accept(); // Crea objeto

				System.out.println("Hola Servidor " );
				//asocio flujo salida de datos al socket
				OutputStream aux = skCliente.getOutputStream();
				//asocio flujo de datos flujo de tipo DataOutputStream 
				DataOutputStream flujo= new DataOutputStream( aux );
				//escribo
				do{
					
				}while(false);
				flujo.writeUTF( "Hola cliente " );
				System.out.println("Adios Servidor");
				OutputStream aux2 = skCliente.getOutputStream();
				DataOutputStream flujo2= new DataOutputStream( aux );
				flujo2.writeUTF( "Adios cliente" );
				//cierro conexión
				skCliente.close();
			}//fin for
			System.out.println("Demasiados clientes por hoy");

		} catch( Exception e ) {

	System.out.println( e.getMessage() );

	}

}

public static void main( String[] arg ) {

new Servidor();

}

}
