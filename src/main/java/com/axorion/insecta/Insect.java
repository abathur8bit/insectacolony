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

/**
 * Base class for any type of insect, handling all the common insect functions.
 * Create your insect by passing in it's name, and the string representation of the type.
 */
public abstract class Insect extends NamedEntity {
    private final String type;
    protected int counter=0;
    protected Colony colony;
    protected State currentState;

    protected int money=0;
    protected int fatigue=0;
    protected int hunger=0;

    protected Room.Name currRoomNum;      //currently located room

    public Insect(String name,String type) {
        super(name);
        this.type = type;
        currentState = EnterColonyStartWorking.getInstance();
    }
    public void update(long now) {
        hunger++;
        if(currentState != null) {
            currentState.execute(this);
        }
    }
    public String getType() {
        return type;
    }
    protected void changeState(State newState) {
        if(currentState != null) {
            currentState.exit(this);
        }
        currentState = newState;

        if(currentState != null) {
            currentState.enter(this);
        }
    }
    public void changeLocation(Room.Name room) {
        currRoomNum = room;
    }
    public void sleep() {
        if(fatigue>0) {
            --fatigue;
        }
    }
    public boolean isDoneWorking() {
        return fatigue > 5 + RandomTool.rnd(1, 5);
    }
    public boolean isDoneSleeping() {
        return fatigue==0;
    }
    @Override
    public String toString() {
        return type+" "+getName();
    }
}