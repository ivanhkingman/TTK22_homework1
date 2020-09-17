#include <IMC/Spec/Abort.hpp>
#include <IMC/Base/ByteBuffer.hpp>
#include <IMC/Spec/PlanSpecification.hpp>
#include <IMC/Base/Packet.hpp>
#include <IMC/Base/Factory.cpp>
#include "UDP/DatagramSocket.cpp"
#include <iostream>
#include <vector>
#define LAUVXPLORE1 (30)
using namespace IMC;

int main() {
    char localhost[] = "127.0.0.1";

    Abort abort;
    abort.setDestination(LAUVXPLORE1);
    abort.setSource(16652);
    abort.setTimeStamp(0);
    abort.setDestinationEntity(255);
    
    PlanSpecification planSpecification;

    
    //Header fields
    planSpecification.setTimeStamp(1.5628304294681385E9);       // Seconds since 01-jan-1970                      
    planSpecification.setDestination(LAUVXPLORE1);              // specify destination (otherwise DUNE will reject it)
    planSpecification.setSource(16652);                 // The Source IMC system ID.
    planSpecification.setSourceEntity(44);              // The entity generating this message at the source address.
    planSpecification.setDestinationEntity(255);        // The entity that should process this message at the destination address.

    //Plan specific fields
    planSpecification.plan_id = "cmd-lauv-xplore-1";    // The plan’s identifier.
    planSpecification.start_man_id = "1";               // Indicates the id of the starting maneuver for this plan.
    

    //TODO: Specify maneuvers
    

    int size = planSpecification.getSerializationSize();                    // calculate bytes required for serialization
    char buffer[size];                                                      // allocate same number of bytes
    Packet::serialize(&planSpecification, (uint8_t *) buffer, size);        // serialize message
        
    DatagramSocket socket(6001, localhost, true, true);         // see https://github.com/butcherg/DatagramSocket
    socket.sendTo(buffer, size, localhost);                     // send message to 127.0.0.1:6002

    //TODO: Functionality for writing message to JSON file

    std::cout << "Message sent to LAUV-EXPLORE-1" << std::endl;
}