class Productor extends Thread{
	private Cola cola;
	private int n;

	public Productor (Cola c,int n){
		cola=c;
		this.n=n;
	}
	
	public void run(){
		for (int i=0;i<5;i++){
			String valor="";
			if(i%2==0){
				cola.put("PONG");
				valor = "PONG";
			}else{
				cola.put("PING");
				valor = "PING";
			}
			
			 //pone el número
			System.out.println(i	+"->Productor: "+valor);
			
 			try {
				sleep(100);
			}catch (InterruptedException e){}
		}
	}
}
