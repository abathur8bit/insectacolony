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

/** Brood Chamber is a place to refresh fatigue and restore health. */
public class VisitBroodChamber extends State {
    private static final VisitBroodChamber instance = new VisitBroodChamber();

    public static Room.Name getName() {
        return Room.Name.BROOD_CHAMBER;
    }

    public static VisitBroodChamber getInstance() {
        return instance;
    }

    public void enter(Insect bug) {
        final Room.Name destRoom = getName();
        if(bug.currRoomNum != destRoom) {
            System.out.println(bug+" is entering "+destRoom);
            bug.changeLocation(destRoom);
        }
    }
    public void execute(Insect bug) {
        System.out.println(bug+" is sleeping fatigue="+bug.fatigue);
        bug.sleep();
        if(bug.isDoneSleeping()) {
            bug.changeState(EnterColonyStartWorking.getInstance());
        }
    }
    public void exit(Insect bug) {
        System.out.println(bug+" leaving "+getName().toString());
    }
}
