#include "StateOutputPortAnalizer.h"


StateOutputPortAnalizer::StateOutputPortAnalizer()
{
    _jointIndexList= {0, 1, 2};
}

StateOutputPortAnalizer::StateOutputPortAnalizer(std::string jil)
{
    std::string jointindex;
    std::istringstream iss(jil);
    while (std::getline(iss, jointindex, ','))
    {
        _jointIndexList.push_back(std::stoi(jointindex));
    }
}

StateOutputPortAnalizer::~StateOutputPortAnalizer()
{
    ;
}

bool StateOutputPortAnalizer::generateOutputInfoLog(std::string basepath, std::string subpart)
{
    std::ifstream info_log_in(basepath+subpart+"/info.log");
    if (!info_log_in.is_open())
    {
        std::cerr << "info.log file not found in input directory. Cannot proceed.\n";
        return false;
    }
    
    std::ofstream info_log_out(basepath+"/out/"+subpart+"/info.log");
    if (!info_log_out.is_open())
    {
        std::cerr << "Unable to open file. Cannot proceed.\n";
        return false;
    }
    else
    {
        std::string line;

        while (std::getline(info_log_in, line))
        {
            info_log_out << line << std::endl;
        }

        info_log_out.close();
    }
    return true;
}

void StateOutputPortAnalizer::readWriteInputData(std::string iFilename, std::string oFilename)
{    
    std::string line;
    std::ifstream inputFile(iFilename);
    outputDataStream.open(oFilename);
    if (inputFile.is_open() && outputDataStream.is_open())
    {
        while (std::getline(inputFile, line))
        {
            std::stringstream linestream(line);
            std::vector<std::string> inputValues;
            std::string value;
            while (std::getline(linestream, value, ' '))
            {
                inputValues.push_back(value);
            }
            
            for (auto& i : _jointIndexList)
            {
                
                outputDataStream << inputValues[i] << " ";
            }
            outputDataStream << std::endl;
        }

        inputFile.close();
        outputDataStream.close();
    }
    else
    {
        std::cerr << "Unable to open files\n";
    }
}
