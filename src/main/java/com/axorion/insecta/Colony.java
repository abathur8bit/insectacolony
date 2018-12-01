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
    public void addInsectToRoom(Insect bug,Room r) {
        insects.put(bug.getName(),bug);
        r.addInsect(bug);
    }
    public void removeInsect(Insect bug) {
        insects.remove(bug.getName());
        removeInsectFromRoom(bug);
    }
    public void addRoom(Room r) {
        rooms.put(r.getName(),r);
    }
    public void removeRoom(Room r) {
        rooms.remove(r.getName());
    }
    public void update(long now) {
        for(Room r : rooms.values()) {
            r.update(now);
        }
        for(Insect bug : insects.values()) {
            bug.update(now);
        }
    }
    public void removeInsectFromRoom(Insect bug) {
        for(Room r : rooms.values()) {
            r.removeInsect(bug);
        }
    }
    public void showState() {

    }
}
