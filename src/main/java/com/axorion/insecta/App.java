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
        kitchen.addInsect(new Beetle("Bob"));
        kitchen.addInsect(new Beetle("Frank"));
        hive.update();
    }
}
