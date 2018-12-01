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
    protected int counter=0;
    protected Colony colony;
    protected State currentState=null;

    protected int money=0;
    protected int fatigue=0;
    protected int hunger=0;

    protected Room.Name currRoomNum;      //currently located room

    public Insect(String name,String type) {
        super(name);
        this.type = type;
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
        if(fatigue>5+RandomTool.rnd(1,5)) {
            return true;
        }
        return false;
    }
    public boolean isDoneSleeping() {
        return fatigue==0;
    }
    @Override
    public String toString() {
        return type+" "+getName();
    }
}