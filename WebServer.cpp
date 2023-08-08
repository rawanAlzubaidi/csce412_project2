#include "WebServer.h"
#include <fstream> 
#include <ctime> 
#include <iostream> 
using namespace std; 

WebServer::WebServer()  : available(true), process_end_time(0){
}

WebServer::~WebServer() {
}

/**
 * @brief Log a message to the console and a file.
 * 
 * This function logs a message both to the console and to a log file named "output.txt".
 * 
 * @param message The message to be logged.
 */
void logFileMsg(const string &message)
{
    cout << message << endl; 
    ofstream logFile("logfile.txt", std::ios_base::app); 
    logFile << message << endl;
}

/**
 * @brief Accept a request for processing.
 * 
 * This function accepts an incoming request for processing if the server is currently available.
 * 
 * @param request The request to be processed.
 * @return True if the request is accepted, false otherwise.
 */
bool WebServer::acceptRequest(const Request &request) {
    if (time(0) >= this->process_end_time)
    {
        this->thisRequest = request;
        this->available = false;
        processRequest();
        return true;
    }
    return false;
}

/**
 * @brief Process the accepted request.
 * 
 * This function processes the previously accepted request and logs the details.
 */
void WebServer::processRequest() {
    logFileMsg("Web Server accepted a request from " + thisRequest.ip_input + " to " + thisRequest.ip_output + " with time " + std::to_string(thisRequest.time));
    this->available = true;  //set server to available 
}

/**
 * @brief Check if the server is available for processing.
 * 
 * This function checks if the server is available for processing new requests.
 * 
 * @return True if the server is available, false otherwise.
 */
bool WebServer::checkAvailability()
{
    if (time(0) >= this->process_end_time)
    {
        this->available = true;
    }
    return this->available;
}
