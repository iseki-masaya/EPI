package com.company;

import java.util.Date;
import java.util.Random;

/**
 * Created by iseki on 2014/11/14.
 */
class Writer extends Thread {
    public void run() {
        Random rnd = new Random();
        while (true) {
            synchronized (RW.LW) {
                boolean done = false;
                while (!done) {
                    synchronized (RW.LR) {
                        if (RW.readCount == 0) {
                            RW.data = new Date().toString();
                            System.out.println("Write");
                            done = true;
                        } else {
                            try {
                                RW.LR.wait();
                            } catch (InterruptedException e){
                                System.out.println("InterruptedException in Writer wait");
                            }
                        }
                        RW.LR.notify();
                    }
                }
            }
            int n = rnd.nextInt(10);
            try{
                Thread.sleep(n*300);
            }catch(InterruptedException e){}
        }
    }
}
