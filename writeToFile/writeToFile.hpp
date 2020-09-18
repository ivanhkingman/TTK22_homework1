#include <fstream>
#include <IMC/Spec/PlanSpecification.hpp>


void writeToLogFile(std::string logFileName, IMC::PlanSpecification planSpecification) {
    std::fstream logFile;
    logFile.open(logFileName, std::ios::out);
    logFile << "{" << std::endl;
    //TODO: Fix "," that appears at the beginning when using this function
    planSpecification.fieldsToJSON(logFile, 5);
    logFile << std::endl;
    logFile << "}" << std::endl;
    logFile.close();
};

