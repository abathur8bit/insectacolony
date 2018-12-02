package com.axorion.insecta;

/* *****************************************************************************
 * Copyright 2018 Lee Patterson <https://github.com/abathur8bit>
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
 * ******************************************************************************/

import java.util.Collection;
import java.util.HashMap;

/** Rooms contain insects, and provide a place for the insect to interact in. */
public class Room extends NamedEntity {
    enum Name {
        LIMBO,
        HIVE,
        KITCHEN,
        BROOD_CHAMBER
    }
    protected final HashMap<String,Insect> insects = new HashMap<String,Insect>();

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
