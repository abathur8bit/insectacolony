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

/** Works the insect until they are fatigued, then sends them to the brood chamber. */
public class EnterColonyStartWorking extends State {
    private static final EnterColonyStartWorking instance = new EnterColonyStartWorking();
    public static Room.Name getName() {
        return Room.Name.BROOD_CHAMBER;
    }

    public static EnterColonyStartWorking getInstance() {
        return instance;
    }
    public void enter(Insect bug) {
        if(bug.currRoomNum != Room.Name.HIVE) {
            System.out.println(bug+" is entering "+Room.Name.HIVE);
            bug.changeLocation(Room.Name.HIVE);
        }
    }
    public void execute(Insect bug) {
        bug.money++;
        bug.fatigue++;

        System.out.println(bug+" is working hard fatigue="+bug.fatigue);

        if(bug.isDoneWorking()) {
            bug.changeState(VisitBroodChamber.getInstance());
        }
    }
    public void exit(Insect bug) {
        System.out.println(bug+" leaving "+getName());
    }
}
