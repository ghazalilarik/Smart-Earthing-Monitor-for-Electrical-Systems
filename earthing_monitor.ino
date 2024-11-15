#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "YourWiFiSSID";       // Replace with your WiFi SSID
const char* password = "YourWiFiPassword"; // Replace with your WiFi Password

// Simulating earthing resistance measurement
int earthResistancePin = A0;  // Analog pin for the simulated earthing resistance

WiFiServer server(80); // Start server on port 80

void setup() {
  Serial.begin(115200);
  pinMode(earthResistancePin, INPUT);

  Serial.println();
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin(); // Start the server
}

void loop() {
  WiFiClient client = server.available(); // Check if a client has connected
  if (!client) {
    return;
  }

  Serial.println("New Client Connected");
  while (!client.available()) {
    delay(1);
  }

  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // Simulate resistance measurement
  int earthResistance = analogRead(earthResistancePin); // Simulated analog input
  float resistanceValue = earthResistance * (3.3 / 1023.0) * 100; // Convert to resistance value

  String status = (resistanceValue < 50) ? "Good Earthing" : "Poor Earthing";

  // Send HTTP response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println();
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<h1>Smart Earthing Monitor</h1>");
  client.println("<p>Resistance: " + String(resistanceValue, 2) + " ohms</p>");
  client.println("<p>Status: " + status + "</p>");
  client.println("</html>");

  delay(1);
  Serial.println("Client Disconnected");
}
