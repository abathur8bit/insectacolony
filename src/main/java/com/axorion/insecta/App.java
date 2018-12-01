package com.axorion.insecta;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
        Colony hive = new Colony("Alpha Hive");
        Room kitchen = new Room("Kitchen");
        hive.addRoom(kitchen);
        hive.addInsectToRoom(new Beetle("Bob"),kitchen);
//        hive.addInsectToRoom(new Beetle("Frank"),kitchen);

        for(int i=0; i<100; i++) {
            long now = System.currentTimeMillis();
            hive.update(now);
        }
    }
}
