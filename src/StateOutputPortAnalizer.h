#ifndef __STATEOUTPUTPORTANALIZER__
#define __STATEOUTPUTPORTANALIZER__

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <iomanip>

class StateOutputPortAnalizer
{
private:
    std::vector<int> _jointIndexList;

    std::ofstream outputDataStream;

public:
    StateOutputPortAnalizer();
    StateOutputPortAnalizer(std::string jil = "0,1,2");
    ~StateOutputPortAnalizer();

    bool generateOutputInfoLog(std::string basepath, std::string subpart);
    void readWriteInputData(std::string iFilename, std::string oFilename);

};





#endif