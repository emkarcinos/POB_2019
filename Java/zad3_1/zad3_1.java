package POB_2019.Java.zad3_1;

import java.io.IOException;
import java.util.List;
import java.util.ArrayList;

public class zad3_1 {
    public static void main(String[] args) throws IOException {
        Logger log1 = new StdoutLogger();
        Logger log2 = new FileLogger();
        List<String> texts = new ArrayList<String>();
        texts.add("Jechane");
        texts.add("ASDSAD");
        texts.add("Jechane1");
        for(String text : texts){
            log1.log(text);
            log2.log(text);
        }
    }
}