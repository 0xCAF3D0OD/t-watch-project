#include "backend.hpp"
#include <HTTPClient.h>

using namespace std;

void	backend()
{
	HTTPClient http;
	Serial.begin(115200);
	Serial.printf("1\n");
    http.begin("http://mes.42lausanne.ch/");		//Specify request destination
	Serial.printf("2\n");
    int httpCode = http.GET();              		//Send the request
	Serial.printf("3\n");

    if (httpCode > 0) { 							//Check the returning code
	  printf("4\n");
      String payload = http.getString();  		 	//Get the request response payload
	  printf("5\n");
     Serial. printf("%s\n", payload);						//Print the response payload
    }
	printf("6\n");

    http.end(); 
}
