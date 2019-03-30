#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Logger{
    public:
        virtual void log(string textToLog)=0;
        virtual void del(){};

        vector<string> history;
        
    protected:
        virtual void history_add(string textToLog){
            history.push_back(textToLog);
        }
};

class FileLogger : public Logger{
    public:
        FileLogger(string filePath){
            logFile.open(filePath);
        }
        void log(string textToLog){
            history_add(textToLog);
            logFile << textToLog << "\n";
        }
        void del(){
            logFile.close();
        }
    private:
        ofstream logFile;
};

class StdoutLogger : public Logger{
    public:
        void log(string textToLog){
            history_add(textToLog);
            cout << textToLog << "\n";
        }
};

void saveLogs(vector<Logger*> &logs, string text){
    for(Logger* l : logs)
        l->log(text);
}

void stopLogging(vector<Logger*> &logs){
    for(Logger* l : logs)
        l->del();
}

int main(void){
    vector<Logger*> logs={new FileLogger("/home/marcin/Documents/Coding/POB_2019/logs/log1.txt"),
                        new FileLogger("/home/marcin/Documents/Coding/POB_2019/logs/log2.txt"),
                        new StdoutLogger()};
    vector<string> texts={"cpp1", "cpp2", "ilovecpp", "linuxoverwindows"};
    for(string text : texts)
        saveLogs(logs, text);
    stopLogging(logs);

}



