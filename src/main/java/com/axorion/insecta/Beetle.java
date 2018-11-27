package com.axorion.insecta;

public class Beetle extends Insect {
    private static final String TYPE = "Beetle";

    public Beetle(String name) {
        super(name,TYPE);
    }

    @Override
    public void update() {
        System.out.println("Update type=["+getType()+"] name=["+getName()+"] state=["+getState()+"].");
    }
}
