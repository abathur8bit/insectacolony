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

/**
 * Test the state machine by creating a colony with a room and a couple insects.
 */
public class App 
{
    public static void main( String[] args )
    {
        Colony hive = new Colony("Alpha Hive");
        Room kitchen = new Room("Kitchen");
        hive.addRoom(kitchen);
        hive.addInsectToRoom(new Beetle("Bob"),kitchen);
        hive.addInsectToRoom(new Beetle("Frank"),kitchen);

        //simulate for a number of cycles
        for(int i=0; i<100; i++) {
            long now = System.currentTimeMillis();
            hive.update(now);
        }
    }
}
