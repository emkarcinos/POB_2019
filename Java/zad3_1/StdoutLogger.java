package POB_2019.Java.zad3_1;

public class StdoutLogger extends Logger {
    @Override
    public void log(String textToLog){
        System.out.println(textToLog);
    }
}