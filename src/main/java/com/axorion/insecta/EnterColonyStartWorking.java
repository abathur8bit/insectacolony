package com.axorion.insecta;

public class EnterColonyStartWorking extends State {
    private static final EnterColonyStartWorking instance = new EnterColonyStartWorking();

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
        System.out.println(bug+" leaving the hive");
    }
}
