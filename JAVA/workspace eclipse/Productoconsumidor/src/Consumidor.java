class Consumidor extends Thread {
	private Cola cola;
	private int n;

	public Consumidor (Cola c, int n){
		cola=c;
		this.n=n;
	}
	
	public void run(){
		String valor;
		for (int i=0;i<5;i++){
			valor=cola.get();//recoge el numero
			System.out.println(i+"->Consumidor: "+valor);
	 			
		}
	}

}
