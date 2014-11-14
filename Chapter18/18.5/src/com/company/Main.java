package com.company;

import com.sun.jmx.snmp.tasks.Task;

import java.util.Date;

public class Main {

    public static void main(String[] args) {
	// write your code here
        System.out.println("Hello");

        Reader[] r = new Reader[1];
        Writer[] w = new Writer[1];

        for (int i=0; i<r.length; ++i) {
            w[i] = new Writer();
            r[i] = new Reader();
            w[i].start();
            r[i].start();
        }
    }
}