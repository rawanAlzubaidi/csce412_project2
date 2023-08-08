#include <iostream>
#include <random>
#include "LoadBalancer.h"
#include "Request.h"
#include "WebServer.h"
#include <fstream>
using namespace std;

void addToFile(const std::string &message)
{
    ofstream logFile("logfile.txt", ios_base::app);
    logFile << message << endl;
}

int main()
{
    auto generateIP = []() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, 255);
        return to_string(distrib(gen)) + "." + to_string(distrib(gen)) + "." + to_string(distrib(gen)) + "." + to_string(distrib(gen));
    };

    // log of 10 servers running for 10000 clock cycles
    int serversNumber = 10;
    int clockCycles = 10000;
    LoadBalancer loadbalancer(serversNumber); // construct the lb with servernum 

    std::vector<std::string> ipAddresses;
    for (int i = 0; i < serversNumber * 100; ++i)
    {
        ipAddresses.push_back(generateIP());
    }

    for (int i = 0; i < serversNumber * 100; i++)
    {
        string ip_input = ipAddresses[i % ipAddresses.size()];
        string ip_output = ipAddresses[(i + 1) % ipAddresses.size()];
        int time = i % clockCycles;
        Request req = {ip_input, ip_output, time};
        loadbalancer.AddRequest(req);
    }

    addToFile("Starting queue size is " + std::to_string(serversNumber * 100));
    addToFile("Task times range from 0 to " + std::to_string(clockCycles - 1));
    loadbalancer.Balance(clockCycles);

    addToFile("Ending queue size: " + std::to_string(loadbalancer.getQueueSize())); // Log the ending queue size

    return 0;
}
