#include "LoadBalancer.h"

/**
 * @file LoadBalancer.cpp
 * @brief Implementation of the LoadBalancer class.
 */

LoadBalancer::LoadBalancer(int ServerNumber)
{
    for (int i = 0; i < ServerNumber; ++i)
    {
        webServersVec.push_back(new WebServer());
    }
}

LoadBalancer::~LoadBalancer()
{
    for (WebServer *server : this->webServersVec)
    {
        delete server;
    }
}

/**
 * @brief Add a request to the load balancer's queue.
 * 
 * This function adds an incoming request to the queue for processing by the load balancer.
 * 
 * @param request The request to be added to the queue.
 */
void LoadBalancer::AddRequest(const Request &request)
{
    this->requestQ.push(request);
}

/**
 * @brief Balance the incoming requests among the web servers.
 * 
 * This function distributes the incoming requests among the available web servers 
 * in a round-robin fashion, attempting to balance the load among them. It runs 
 * for a given time or until the request queue is empty.
 * 
 * @param runTime The time duration for which the load balancing should run.
 */
void LoadBalancer::Balance(int runTime)
{
    int currentTime = 0;

    while (currentTime < runTime && !requestQ.empty())
    {
        for (auto &server : webServersVec)
        {
            if (server->checkAvailability() && !requestQ.empty())
            {
                Request thisRequest = requestQ.front();
                if (server->acceptRequest(thisRequest))
                {
                    requestQ.pop();
                }
            }
        }
        currentTime++;
    }
}

int LoadBalancer::getQueueSize() const
{
    return this->requestQ.size(); 
}