package com.axorion.insecta;

import java.util.HashMap;

public class Colony extends NamedEntity {
    HashMap<String,Insect> insects = new HashMap<String, Insect>();

    public Colony(String name) {
        super(name);
    }

    public HashMap<String,Insect> getInsects() {
        return insects;
    }
    public void addInsect(Insect bug) {
        insects.put(bug.getName(),bug);
    }
    public void removeInsect(Insect bug) {
        insects.remove(bug.getName());
    }

    public void update() {
        for(Insect bug : insects.values()) {
            bug.update();
        }
    }

    public void showState() {

    }
}
