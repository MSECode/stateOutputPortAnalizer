#include "StateOutputPortAnalizer.h"
#include <getopt.h>

void usage()
{
    std::cout <<
        "-p|--part <ROBOT_SUBPART> [e.g. left_arm]:   Set the robot supart\n"
        "-l|--list <LIST_OF JOINTS> [e.g. 0,1,2,3]:   Set the number of joints you are interested in\n"
        "-b|--basepath <BASEPATH> [e.g. data/]:       Basepath directory in which finding the folder of the subpart dumped data\n"       
        "-e|--example:                                An example exection of the program is run\n"
        "-h|--help:                                   Show help\n";

    exit(1);
}

int main(int argc, char * argv[])
{

    const char* const short_opts = "p:l:b:eh"; //colon (:) means that the command has a parameter
    const option long_opts[] = 
    {
        {"part", 1, nullptr, 'p'},
        {"list", 1, nullptr, 'l'},
        {"basepath", 1, nullptr, 'b'},
        {"example", 0, nullptr, 'e'},
        {"help", 0, nullptr, 'h'},
        {nullptr, 0, nullptr, 0}
    };


    //set default value for subpart, number of joints and basepath
    std::string subpart = "left_arm";
    std::string jointslist = "0,1,2";
    std::string basepath = "data/";
    std::string inputFileName = basepath+subpart+"/data.log";
    std::string outputFileName = basepath+"/out/"+subpart+"/data.log";
    

    while (1)
    {
        const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);

        if (-1 == opt)
            break;

        switch (opt)
        {

        case 'e':
            std::cout << "Going to elaborate data using example subpart: " << subpart << " jointslist: " << jointslist << " and basepath: " << basepath << std::endl;
            break;

        case 'p':
            subpart = optarg;
            std::cout << "Set robot supart: " << subpart << std::endl;
            continue;
        
        case 'l':
            jointslist = optarg;
            std::cout << "Set joints list: " << jointslist << std::endl;
            
            continue;
        
        case 'b':
            basepath = optarg;
            std::cout << "Set basepath to subpart data folder: " << basepath << std::endl;
            continue;

        case 'h': // -h|--help
        case '?': // Unrecognized option
        default:
            usage();
            break;
        }

        break;
    }

    StateOutputPortAnalizer sopa(jointslist);
    if(!sopa.generateOutputInfoLog(basepath, subpart))
    {
        std::cerr << "Intialization error. Aborting...\n";
        return -3;
    }

    sopa.readWriteInputData(inputFileName, outputFileName);

    return 0;
}