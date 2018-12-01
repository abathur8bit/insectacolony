package com.axorion.insecta;

public abstract class State {
    public abstract void enter(Insect bug);
    public abstract void execute(Insect bug);
    public abstract void exit(Insect bug);
}
