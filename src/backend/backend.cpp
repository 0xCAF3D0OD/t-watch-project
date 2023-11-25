#include "backend.hpp"
#include <HTTPClient.h>

using namespace std;

void	backend()
{
	HTTPClient http;
	// Serial.begin(115200);
	Serial.println("1\n");
    http.begin("http://mes.42lausanne.ch/");		//Specify request destination
	Serial.println("2\n");
    int httpCode = http.GET();              		//Send the request
	Serial.println("3\n");

    // if (httpCode > 0) { 							//Check the returning code
	//   Serial.println("4\n");
    //   String payload = http.getString();  		 	//Get the request response payload
	//   Serial.println("5\n");
    //  Serial.println(payload);						//Print the response payload
    // }
	// Serial.println("6\n");

    http.end(); 
}
