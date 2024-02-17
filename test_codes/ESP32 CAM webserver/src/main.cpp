#include "Arduino.h"
#include "esp_camera.h"
#include "WiFi.h"
#include "ESPAsyncWebServer.h"

const char *ssid = "your-ssid";
const char *password = "your-password";

AsyncWebServer server(80);

void setup() {
    Serial.begin(115200);

    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");

    // Camera setup
    camera_config_t config;
    esp_err_t err = esp_camera_init(&config);
    if (err != ESP_OK) {
        Serial.printf("Camera init failed with error 0x%x", err);
        return;
    }

    // Route for root / web page
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(S_IFIFO, "/index.html", String(), false);
    });

    // Start server
    server.begin();
}

void loop() {
    // Your loop code here
}
