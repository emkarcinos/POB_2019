package POB_2019.Java.zad3_1;

import java.io.FileWriter;
import java.io.IOException;

public class FileLogger extends Logger {
    private FileWriter fileWriter;
    public FileLogger() throws IOException {
        String fileName = "./log.txt";
        this.fileWriter = new FileWriter(fileName);
    }
    @Override
    public void log(String textToLog) throws IOException {
        this.fileWriter.append(textToLog);
        this.fileWriter.append("\n");
        fileWriter.flush();
    }
}