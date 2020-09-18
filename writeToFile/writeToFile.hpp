#include <fstream>
#include <IMC/Spec/PlanSpecification.hpp>


void writeToLogFile(std::string logFileName, IMC::PlanSpecification planSpecification) {
    
    std::fstream logFile;

    logFile.open(logFileName, std::ios::out);
    planSpecification.toJSON(logFile);
    logFile.close();

    logFile.open(logFileName, std::ios::in);
    std::string logFileContent ((std::istreambuf_iterator<char>(logFile) ),
                       (std::istreambuf_iterator<char>()    ) );
    logFile.close();
    logFileContent.pop_back(); logFileContent.pop_back(); logFileContent.pop_back();

    logFile.open(logFileName, std::ios::out);
    logFile << logFileContent;
    planSpecification.fieldsToJSON(logFile, 2);
    logFile << std::endl << "}";
    logFile.close();

};

