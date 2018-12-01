package com.axorion.insecta;

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
