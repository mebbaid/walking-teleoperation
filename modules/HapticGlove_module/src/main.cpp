// SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
// SPDX-License-Identifier: BSD-3-Clause

// YARP
#include <yarp/os/LogStream.h>
#include <yarp/os/Network.h>
#include <yarp/os/RFModule.h>

#include <HapticGloveModule.hpp>

int main(int argc, char* argv[])
{
    // initialise yarp network
    yarp::os::Network yarp;
    if (!yarp.checkNetwork())
    {
        yError() << "[main] Unable to find YARP network";
        return EXIT_FAILURE;
    }

    // prepare and configure the resource finder
    yarp::os::ResourceFinder& rf = yarp::os::ResourceFinder::getResourceFinderSingleton();

    rf.setDefaultConfigFile("hapticGloveConfig.ini");

    if (!rf.configure(argc, argv))
    {
        yError() << "[main] resource finder cannot find hapticGloveConfig.ini file.";
        return EXIT_FAILURE;
    }

    // create the module
    HapticGloveModule module;

    return module.runModule(rf);
}
