package com.axorion.insecta;

public class Beetle extends Insect {
    private static final String TYPE = "Beetle";
    private static final int CYCLES_SLEEP=3;
    private static final int CYCLES_WAKING=1;

    public Beetle(String name) {
        super(name,TYPE);
        counter = 3;    //sleeping for 3 cycles
    }

    @Override
    public void update(long now) {
        System.out.println(getName()+" is "+getState());
        switch(getState()) {
            case SLEEPING: updateSleep(now); break;
            case WAKING: updateWaking(now); break;
            default:
                System.out.println(TYPE+" in state=["+getState()+"]");
                break;
        }
    }

    @Override
    public void enterState() {
        System.out.println("Beetle override name=["+getName()+"] is entering state=["+getState()+"]");
    }

    @Override
    public void exitState() {
        System.out.println("Beetle override name=["+getName()+"] is exiting state=["+getState()+"]");
    }

    private void updateSleep(long now) {
        if(--counter <= 0) {
            setState(State.WAKING);
            counter = CYCLES_WAKING+RandomTool.rnd(0,10);
        }
    }

    private void updateWaking(long now) {
        if(--counter <= 0) {
            setState(State.HUNGRY);
        }
    }
}
