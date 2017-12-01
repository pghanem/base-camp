/*---------------------------------------------------------------------
                  runway program
  ----------------------------------------------------------------------*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "runway.h"
using namespace std;

int landingTime;
int takeoffTime;
int landingRate; 
int takeoffRate;
int simTime;
int flightNumber = 1000;
int takeoffQueueSize = 0;
int landingQueueSize = 0;

Queue landingQueue;
Queue takeoffQueue;


int main(void)
{

  srand(time(0));

  
  cout << "Enter: " << endl;
  cout << " Time for a plane to land (in minutes): ";
  cin >> landingTime;
  
  cout << " Time for a plane to takeOff (in minutes): ";
  cin >> takeoffTime;
  
  cout << " Landing rate (planes per hour): ";
  cin >> landingRate;
  
  cout << " Takeoff rate (planes per hour): ";
  cin >> takeoffRate;

  cout << " How long to run the simulation (in minutes): ";
  cin >> simTime;

  for(int i = 0; i < simTime; i++){

    cout << "Program start. Simulation time: " << simTime;
    
    if(countdown > 0){
      countdown--;
    }
    if(countdown == 0) {
        cout << "Runway shenanigans are over";
    }
    
    randomPlane(i);

    if(countdown == 0){
      if(landingQueue.empty()){
        if(!takeoffQueue.empty()){
            currentFlightNum = takeoffQueue.front();
            totalTakeoffWaitingTime = totalTakeoffWaitingTime + currentTime - takeoffQueue.getArrivalTimeFromFront();
            totalPlanesTakenOff++;
            takeoffQueue.dequeue();
            takeoffQueueSize--;
            runwayTime = ttake;
            isLanding = false;
        }
      } else {
        currentFlightNum = landingQueue.front();
        totalLandingWaitingTime = totalLandingWaitingTime + currentTime - landingQueue.getArrivalTimeFromFront();
        totalPlanesLanded++;
        landingQueue.dequeue();
        landingQueueSize--;
        runwayTime = tland;
        isLanding = true;
    }
    }


  }

  void randomPlane(const int minutes)
{
    int r1 = rand() % 60;
    int r2 = rand() % 60;
    
    if(r1 < r2) {
      landingQueue.enqueue(flightNumber);
      cout << "Plane #" << flightNumber << " wants to land; added to landing queue;" << landingQueueSize << " in queue" << endl;
      flightNumber++;

    }
    else if(r2 < r1) {
      takeoffQueue.enqueue(flightNumber)
      cout << "Plane #" << flightNumber << " wants to take off; added to takeoff queue;" << takeoffQueueSize << " in queue" << endl;
      flightNumber++;
    }
}

  return 0;

}