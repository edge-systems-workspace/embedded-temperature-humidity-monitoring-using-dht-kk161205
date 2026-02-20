/**
* @file main.ino
 * @brief Embedded Temperature & Humidity Monitoring using DHT11
 * @author kk161205
 * @date 2026-02-20
 *
 * @details
 * This program implements a structured environmental monitoring system
 * using the DHT11 sensor with Arduino Uno R4.
 *
 * Features:
 * - Initializes Serial communication
 * - Initializes DHT11 sensor
 * - Reads temperature and humidity
 * - Validates sensor readings
 * - Prints structured formatted output
 *
 * Library Required:
 * - Adafruit DHT Sensor Library
 */


#include <DHT.h>

// ==========================
// Configuration Section
// ==========================

#define DHTPIN   2       ///< Digital pin connected to DATA
#define DHTTYPE  DHT11   ///< Define DHT11 sensor type

DHT dht(DHTPIN, DHTTYPE);

const unsigned long READ_INTERVAL = 2000;  ///< Sensor read interval in milliseconds

// ==========================
// Function Prototypes
// ==========================

/**
 * @brief Arduino setup function
 *
 * Initializes Serial communication and DHT sensor.
 */
void setup();

/**
 * @brief Arduino main loop
 *
 * Periodically reads temperature and humidity data,
 * validates readings, and prints structured output.
 */
void loop();

// ==========================
// Function Definitions
// ==========================

void setup()
{
    // Initialize Serial Communication
    Serial.begin(9600);

    Serial.println("====================================");
    Serial.println("  DHT11 Temperature & Humidity Monitor");
    Serial.println("  System Initializing...");
    Serial.println("====================================");

    // Initialize DHT Sensor
    dht.begin();

    Serial.println("Sensor initialization complete.");
    Serial.println("Reading environmental data...\n");
}

void loop()
{
    // Wait for defined interval
    delay(READ_INTERVAL);

    // Read sensor values
    float humidity    = dht.readHumidity();
    float temperature = dht.readTemperature();   // Celsius


    // ==========================
    // Validation Section
    // ==========================

    if (isnan(humidity) || isnan(temperature))
    {
        Serial.println("[ERROR] Failed to read from DHT11 sensor.");
        Serial.println("Verify wiring and sensor condition.\n");
        return;
    }

    // ==========================
    // Structured Output Section
    // ==========================

    Serial.println("----------- Environmental Data -----------");

    Serial.print("Temperature : ");
    Serial.print(temperature, 1);
    Serial.println(" °C");

    Serial.print("Humidity    : ");
    Serial.print(humidity, 1);
    Serial.println(" %");

    Serial.println("------------------------------------------\n");
}