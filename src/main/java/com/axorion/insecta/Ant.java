package com.axorion.insecta;

public class Ant extends Insect {
    public static final String TYPE="Ant";

    public Ant(String name) {
        super(name,TYPE);
    }
    @Override
    public void update(long now) {
        hunger++;

    }

}
