package POB_2019.Jerzy;

import java.awt.EventQueue;

public class main {
    public static void main (String[] args){
        EventQueue.invokeLater(new Runnable(){
            public void run(){
                new Okno();
            }
        }); 
    }
}