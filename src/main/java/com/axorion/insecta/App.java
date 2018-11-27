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
        hive.addInsect(new Beetle("Bob"));
        hive.addInsect(new Beetle("Frank"));
        hive.update();
    }
}
