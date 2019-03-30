import os

class Logger():
    def __init__(self):
        self.history=[]
    def history_add(self, textToLog):
        self.history.append(textToLog)
    def log(self, textToLog):
        self.history_add(textToLog)
    def __del__(self):
        pass

class FileLogger(Logger):
    def __init__(self, filePath):
        self.history=[]
        self.logFile=open(filePath, "a+")
    def log(self, textToLog):
        self.history_add(textToLog)
        self.logFile.write(textToLog + "\n")
    def __del__(self):
        self.logFile.close()

class StdoutLogger(Logger):
    def log(self, textToLog):
        self.history_add(textToLog)
        print(textToLog)


def saveLogs(loggers, text):
    for log in loggers:
        log.log(text)

def stopLogging(loggers):
    for log in loggers:
        del log 


dir=os.path.join(os.path.dirname(__file__), "logs")

loggers=[StdoutLogger(), 
        FileLogger(os.path.join(dir, "log1.txt")),
        FileLogger(os.path.join(dir, "log2.txt"))]

texts=["123", "456", "789",
    "abc", "qwe"]

for line in texts:
    saveLogs(loggers, line)

stopLogging(loggers)