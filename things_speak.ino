 #include <DHT.h>  
 #include <ESP8266WiFi.h>  
 #include <WiFiClient.h>  
 #include <ThingSpeak.h>  
 #define DHTPIN D3  
 #define DHTTYPE DHT11  
 DHT dht(DHTPIN, DHTTYPE);  
 const char* ssid = "Honor 6X";  
 const char* password = "notapwd";  
 WiFiClient client;  
 unsigned long myChannelNumber = 563560;  
 const char * myWriteAPIKey = "<APIKEY>";  
 uint8_t temperature, humidity, k=0, l=0;  
 void setup()  
 {  
  Serial.begin(115200);  
  dht.begin();  
  delay(10);  
  // Connect to WiFi network  
  Serial.println();  
  Serial.println();  
  Serial.print("Connecting to ");  
  Serial.println(ssid);  
  WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED)  
  {  
   delay(500);  
   Serial.print(".");  
  }  
  Serial.println("");  
  Serial.println("WiFi connected");  
  // Print the IP address  
  Serial.println(WiFi.localIP());  
  ThingSpeak.begin(client);  
 }  
 void loop()   
 {  
  static boolean data_state = false;  
  temperature = dht.readTemperature();  
  humidity = dht.readHumidity();  
  Serial.print("Temperature Value is :");  
  Serial.print(temperature);  
  Serial.println("C");  
  Serial.print("Humidity Value is :");  
  Serial.print(humidity);  
  Serial.println("%");  
  // Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different  
  // pieces of information in a channel. Here, we write to field 1.  
  if(temperature < 255)
  {
      k=temperature;  
  }
   if(humidity < 255)
  {
      l=humidity;  
  }
  if( data_state )  
  {  
   ThingSpeak.writeField(myChannelNumber, 1, k, myWriteAPIKey);  
   data_state = false;  
  }  
  else  
  {  
   ThingSpeak.writeField(myChannelNumber, 2, l, myWriteAPIKey);  
   data_state = true;  
  }  
  delay(30000); // ThingSpeak will only accept updates every 15 seconds.  
 }  
