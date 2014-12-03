import java.applet.Applet;
import java.awt.Button;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class AppletMain extends Applet implements Runnable, ActionListener{

	private Button b1,b2;
	private Font fuente;
	
	public void start(){
		RpasoHilos2Applet rH1 = new RpasoHilos2Applet(1,2,1,1);
		RpasoHilos2Applet rH2 = new RpasoHilos2Applet(10,11,1,1);
		RpasoHilos2Applet rH3 = new RpasoHilos2Applet(20,30,1,1);
		rH1.start();
		rH2.start();
		rH3.start();
	}
	
	public void init(){
		setBackground(Color.yellow);//color de fondo
		
		//añado botón 1 y su listener
		add(b1=new Button("Parar contador 1"));
		b1.addActionListener(this);
				
		//añado botón 2 y su listener
		add(b2=new Button("Parar contador 2"));
		b2.addActionListener(this);
		
		fuente=new Font("Verdana",Font.BOLD,26); //tipo de letra
		
		run();
	}
	
	public void paint(Graphics g){
		g.setFont(fuente);
		g.drawString(Long.toString((long)CONTADOR), 60, 100);//escribe contador
		g.drawString(Long.toString((long)CONTADOR2), 60, 150);
		
	}
	
	@Override
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		
	}

}
