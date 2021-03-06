#include <IMC/Spec/Abort.hpp>
#include <IMC/Base/ByteBuffer.hpp>
#include <IMC/Spec/PlanSpecification.hpp>
#include <IMC/Base/Packet.hpp>
#include <IMC/Base/Factory.cpp>
#include "UDP/DatagramSocket.cpp"
#include <writeToFile/writeToFile.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#define LAUVXPLORE1 (30)
using namespace IMC;

int main() {
    
    // Homework below this line //

    // Plan specification                                      
    PlanSpecification planSpecification;
    planSpecification.setTimeStamp(1.5628304294681385E9);       // Seconds since 01-jan-1970                      
    planSpecification.setDestination(LAUVXPLORE1);              // specify destination (otherwise DUNE will reject it)
    planSpecification.setSource(16652);                         // The Source IMC system ID.
    planSpecification.setSourceEntity(44);                      // The entity generating this message at the source address.
    planSpecification.setDestinationEntity(255);                // The entity that should process this message at the destination address.
    planSpecification.plan_id = "cmd-lauv-xplore-1";            // The plan’s identifier.
    planSpecification.start_man_id = "1";                       // Indicates the id of the starting maneuver for this plan.

    // Plan Maneuver
    PlanManeuver planManeuver;
    planManeuver.maneuver_id = "1";

    // Loiter
    Loiter loiter;
    loiter.timeout = 10000;
    loiter.lat = 0.7188016469344056;
    loiter.lon = -0.15194250254286037;
    loiter.z = 3;
    loiter.z_units = 1;
    loiter.duration = 300;
    loiter.speed = 1000;
    loiter.speed_units = 1;
    loiter.type = 1;
    loiter.radius = 20;
    loiter.length = 1;
    loiter.bearing = 0;
    loiter.direction = 1;
    loiter.custom = "";

    // Set Entity Parameters
    SetEntityParameters setEntityParameters;
    setEntityParameters.name = "LBL";
    
    // Entity Parameter
    EntityParameter entityParameter;
    entityParameter.name = "Active";
    entityParameter.value = "false";
    
    //! Inline message-fields
    MessageList<EntityParameter> parameters;
    parameters.push_back(entityParameter);
    setEntityParameters.params = parameters;

    InlineMessage<Maneuver> data;
    data.set(loiter);
    planManeuver.data = data;

    MessageList<Message> startActions;
    startActions.push_back(setEntityParameters);
    planManeuver.start_actions = startActions;

    MessageList<PlanManeuver> maneuvers;
    maneuvers.push_back(planManeuver);
    planSpecification.maneuvers = maneuvers;

    // Homework above this line //

    int size = planSpecification.getSerializationSize();                    // calculate bytes required for serialization
    char buffer[size];                                                      // allocate same number of bytes
    Packet::serialize(&planSpecification, (uint8_t *) buffer, size);        // serialize message

    char localhost[] = "127.0.0.1";    
    DatagramSocket socket(6001, localhost, true, true);                     // see https://github.com/butcherg/DatagramSocket
    socket.sendTo(buffer, size, localhost);                                 // send message to 127.0.0.1:6002

    std::string logFileName = "messageLog.JSON";
    writeToLogFile(logFileName, planSpecification);

    std::cout << "Message sent to LAUV-EXPLORE-1. Message contents stored in file " << logFileName << std::endl;
}