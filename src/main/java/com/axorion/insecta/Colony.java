package com.axorion.insecta;

import java.util.Collection;
import java.util.HashMap;

public class Colony extends NamedEntity {
    HashMap<String,Insect> insects = new HashMap<String, Insect>();
    HashMap<String,Room> rooms = new HashMap<String, Room>();

    public Colony(String name) {
        super(name);
    }

    public Collection<Insect> getInsects() {
        return insects.values();
    }
    public void addInsect(Insect bug) {
        insects.put(bug.getName(),bug);
    }
    public void removeInsect(Insect bug) {
        insects.remove(bug.getName());
    }
    public void addRoom(Room r) {
        rooms.put(r.getName(),r);
    }
    public void removeRoom(Room r) {
        rooms.remove(r.getName());
    }
    public void update() {
        for(Room r : rooms.values()) {
            r.update();
        }
    }

    public void showState() {

    }
}
