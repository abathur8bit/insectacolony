package com.axorion.insecta;

import java.util.Collection;
import java.util.HashMap;

public class Room extends NamedEntity {
    enum Name {
        LIMBO,
        HIVE,
        KITCHEN,
        BROOD_CHAMBER
    }
    protected HashMap<String,Insect> insects = new HashMap<String,Insect>();

    public Room(String name) {
        super(name);
    }
    public void addInsect(Insect bug) {
        insects.put(bug.getName(),bug);
    }
    public void removeInsect(Insect bug) {
        insects.remove(bug.getName());
    }
    public Collection<Insect> getInsects() {
        return insects.values();
    }
    public void update(long now) {
    }
}
