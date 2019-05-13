package POB_2019.Jerzy;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JButton;
import java.awt.*;

public class Okno extends JFrame {
    public Okno(){
        super("Moje okno");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setPreferredSize(new Dimension(500,500));
        setLocation(100,100);
        setVisible(true);
    }
    @Override
    public void paintComponents(Graphics g){
        super.paintComponents(g);
        Graphics g2 = (Graphics2D) g;
        g2.drawOval(10,10, 490, 490);
        g2.drawRect(100,100, 400, 400);
        setVisible(true);
    }
}