package com.axorion.insecta;

public class Beetle extends Insect {
    private static final String TYPE = "Beetle";
    private static final int CYCLES_SLEEP=3;
    private static final int CYCLES_WAKING=1;

    public Beetle(String name) {
        super(name,TYPE);
        currentState = EnterColonyStartWorking.getInstance();
        counter = 3;    //sleeping for 3 cycles
    }
}
