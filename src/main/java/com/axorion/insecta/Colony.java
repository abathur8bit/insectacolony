package com.axorion.insecta;

/******************************************************************************
 * Copyright 2018 Lee Patterson
 *
 * You may use and modify at will. Please credit me in the source.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/

import java.util.Collection;
import java.util.HashMap;

/**
 * The colony represents the entire world of rooms and insects.
 */
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
