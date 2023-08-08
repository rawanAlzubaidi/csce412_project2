#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"
#include <ctime> 
#include <condition_variable>
#include <iostream> 
using namespace std;

/**
 * @file WebServer.h
 * @brief The WebServer class represents a web server that can process requests.
 * 
 * This class represents a web server that can process incoming requests. It maintains 
 * information about the current request being processed, its availability status, and 
 * the time when the current request processing will end.
 */

/**
 * @class WebServer
 * @brief Represents a web server that can process requests.
 */
class WebServer{
    public: 
        /**
         * @brief Construct a new WebServer object.
         * 
         * The constructor initializes the web server as available and sets the 
         * process_end_time to 0.
         */
        WebServer();

        /**
         * @brief Destroy the WebServer object.
         * 
         * The destructor has an empty body as there is no dynamic memory 
         * allocation in this class.
         */
        ~WebServer();

        /**
         * @brief Accept a request for processing.
         * 
         * This function accepts an incoming request for processing if the server 
         * is currently available.
         * 
         * @param request The request to be processed.
         * @return True if the request is accepted, false otherwise.
         */
        bool acceptRequest(const Request &request);

        /**
         * @brief Process the accepted request.
         * 
         * This function processes the previously accepted request and logs the details.
         */
        void processRequest();

        /**
         * @brief Check if the server is available for processing.
         * 
         * This function checks if the server is available for processing new requests.
         * 
         * @return True if the server is available, false otherwise.
         */
        bool checkAvailability();

    private: 
        Request thisRequest;        /**< The request currently being processed by the web server. */
        bool available;             /**< Flag indicating whether the web server is available for processing. */
        time_t process_end_time;    /**< The time when the current request processing will end. */
};

#endif // WEBSERVER_H
