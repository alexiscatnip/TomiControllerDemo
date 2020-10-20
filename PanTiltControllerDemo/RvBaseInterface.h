#pragma once
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

#include <cpprest/http_listener.h>              // HTTP server
#include <cpprest/json.h>                       // JSON library
#include <cpprest/uri.h>                        // URI library
//#include <cpprest/ws_client.h>                  // WebSocket client
#include <cpprest/containerstream.h>            // Async streams backed by STL containers
#include <cpprest/interopstream.h>              // Bridges for integrating Async streams with STL and WinRT streams
#include <cpprest/rawptrstream.h>               // Async streams backed by raw pointer to memory
#include <cpprest/producerconsumerstream.h>     // Async streams for producer consumer scenarios

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams
using namespace web::http::experimental::listener;          // HTTP server
//using namespace web::experimental::web_sockets::client;     // WebSockets client
using namespace web::json;                                  // JSON library




#include<iostream> 
#include<string> // for string class 

//This class is the interface to communicate with the rvbase. 
//We current assume that the rv base is acting as a restful server, and it has its own router.
//IE: [IPC (client)] --wifi->     [RVrouter--ethernet cable-> RVpc(server)]

class RvBaseInterface
{
public:
	RvBaseInterface(std::string addr);
	//0: NOT_INITIALISED: an 'unknown or undefined' state
	//1: IDLE: no job. the base is idling, and so are we.
	//2: NO_RESPONSE: we are unable to talk to the base at all.
	//3: WAITING_FOR_US: Job: The base is waiting for us (we are stills spraying.).
	//4: MOVING_TO_NEXT_WAYPOINT: Job: We are waiting for the base to get to new loc..
	enum class StatusEnum { NOT_INITIALISED, NO_RESPONSE, IDLE, WAITING_FOR_US, MOVING_TO_NEXT_WAYPOINT, NEW_JOB };
	RvBaseInterface::StatusEnum getStatus();
	int getRobotBaseSprayPattern();
	
	StatusEnum status = StatusEnum::NOT_INITIALISED;
	void reportCompletionToBase(); //Post: tells the robot base that we are done with the spraying.

private:
	std::string demo_url = "https://reqres.in"; //for demo app
	std::string url = "192.168.0.0"; //url (actual)
	void requestSprayJobInfo(); //Get: asks the robot base for the job info at the present location (spray area, for instance.)

	
};
