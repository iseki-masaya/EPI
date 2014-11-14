package com.company;

import java.util.Random;

/**
 * Created by iseki on 2014/11/14.
 */
class Reader extends Thread {
    public void run() {
        Random rnd = new Random();
        while (true) {
            synchronized (RW.LR) {
                RW.readCount++;
                RW.LR.notify();
            }
            System.out.println("Read");
            System.out.println(RW.data);
            synchronized (RW.LR) {
                RW.readCount--;
                RW.LR.notify();
            }

            int n = rnd.nextInt(10);
            try {
                Thread.sleep(n*400);
            }catch(InterruptedException e){}
        }
    }
}
