class Logger {
public:
    // TC: O(1)
    // SC: O(1)
    Logger() {
        logMap = {};      
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(logMap.count(message)) {
            if(timestamp < logMap[message] + 10) 
                return false;
        }

        logMap[message] = timestamp;

        return true;
    }

private:
    unordered_map<string, int> logMap;
};
