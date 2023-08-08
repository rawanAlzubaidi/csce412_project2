#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "WebServer.h"
#include <queue>
#include <vector> 
using namespace std;

/**
 * @file LoadBalancer.h
 * @brief The LoadBalancer class represents a simple load balancer for web servers.
 * 
 * This class manages a collection of WebServer objects and distributes incoming 
 * requests among them to balance the load. It maintains a request queue and assigns 
 * requests to available servers. The LoadBalancer class is responsible for handling 
 * incoming requests and distributing them to the available WebServer instances.
 */

/**
 * @class LoadBalancer
 * @brief Manages a collection of WebServer objects to balance the load of incoming requests.
 */
class LoadBalancer 
{
    public:
        /**
         * @brief Construct a new LoadBalancer object with a given number of web servers.
         * 
         * @param ServerNumber The number of web servers to create and manage.
         */
        LoadBalancer(int ServerNumber);

        /**
         * @brief Destroy the LoadBalancer object and clean up the web server instances.
         */
        ~LoadBalancer();

        /**
         * @brief Add a request to the load balancer's queue.
         * 
         * @param request The request to be added to the queue.
         */
        void AddRequest(const Request &request);

        /**
         * @brief Balance the incoming requests among the web servers.
         * 
         * This function distributes the incoming requests among the available web servers 
         * in a round-robin fashion, attempting to balance the load among them. It runs 
         * for a given time or until the request queue is empty.
         * 
         * @param runtime The time duration for which the load balancing should run.
         */
        void Balance(int runtime);

        /**
         * @brief Log a message related to the load balancer.
         * 
         * This function logs a message related to the load balancer's operation.
         * 
         * @param message The message to be logged.
         */
        void logMessage(const std::string &message);
        int getQueueSize() const;

    private: 
        std::queue<Request> requestQ;                /**< Queue to hold incoming requests. */
        std::vector<WebServer *> webServersVec;      /**< Vector of web servers managed by the load balancer. */
};

#endif // LOADBALANCER_H
