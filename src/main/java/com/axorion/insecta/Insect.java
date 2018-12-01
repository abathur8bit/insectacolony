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

public abstract class Insect extends NamedEntity {
    private String type;
    protected int counter;
    protected int counterMax;
    protected int destinationRoom;
    protected int currentRoom;
    protected State state;
    protected Colony colony;

    protected int money;
    protected int health;
    protected int hunger;

    public abstract void update(long now);

    public Insect(String name,String type) {
        super(name);
        this.type = type;
        state = State.SLEEPING;
    }
    public String getType() {
        return type;
    }
    public State getState() {
        return state;
    }
    public void setState(State s) {
        exitState();
        state = s;
        enterState();
    }
    public void enterState() {
        System.out.println("name=["+getName()+"] entering state=["+getState()+"]");
    }
    public void exitState() {
        System.out.println("name=["+getName()+"] exiting state=["+getState()+"]");
    }

    private void updateSleep(long now) {
        if(--counter <= 0) {
            setState(State.WAKING);
            counter = RandomTool.rnd(1,2);
        }
    }

    private void updateWaking(long now) {
        if(--counter <= 0) {
            setState(State.HUNGRY);
        }
    }


}