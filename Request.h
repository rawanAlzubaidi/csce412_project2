#ifndef REQUEST_H
#define REQUEST_H

#include <string>

/**
 * @file Request.h
 * @brief The Request struct represents a request from a client to the load balancer.
 * 
 * This struct defines a request made by a client to the load balancer. It contains 
 * the client's input IP address, the output IP address to which the request should 
 * be forwarded, and the time duration the request will take to process (in cycles).
 */
struct Request
{
    std::string ip_input;  /**< The input IP address of the client making the request. */
    std::string ip_output; /**< The output IP address to which the request should be forwarded. */
    int time;              /**< The time duration the request will take to process (in cycles). */
};

#endif // REQUEST_H
