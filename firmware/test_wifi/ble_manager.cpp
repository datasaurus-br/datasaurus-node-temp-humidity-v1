#include "ble_manager.h"

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>

BLEManager bleManager;

static BLEServer* server = nullptr;

static const char* SERVICE_UUID =
    "91bad492-b950-4226-aa2b-4ede9fa42f59";

static const char* SSID_UUID =
    "cba1d466-344c-4be3-ab3f-189f80dd7518";

static const char* PASSWORD_UUID =
    "cba1d466-344c-4be3-ab3f-189f80dd7519";

class SSIDCallback : public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic* characteristic) override {
        String value = characteristic->getValue();

        if (!value.isEmpty()) {
            bleManager.setSSID(value);
        }
    }
};

class PasswordCallback : public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic* characteristic) override {
        String value = characteristic->getValue();

        if (!value.isEmpty()) {
            bleManager.setPassword(value);
        }
    }
};

void BLEManager::setup() {
    BLEDevice::init("Datasaurus Setup");

    server = BLEDevice::createServer();

    BLEService* service =
        server->createService(SERVICE_UUID);

    BLECharacteristic* ssidCharacteristic =
        service->createCharacteristic(
            SSID_UUID,
            BLECharacteristic::PROPERTY_WRITE
        );

    BLECharacteristic* passwordCharacteristic =
        service->createCharacteristic(
            PASSWORD_UUID,
            BLECharacteristic::PROPERTY_WRITE
        );

    ssidCharacteristic->setCallbacks(
        new SSIDCallback()
    );

    passwordCharacteristic->setCallbacks(
        new PasswordCallback()
    );

    service->start();

    BLEAdvertising* advertising =
        BLEDevice::getAdvertising();

    advertising->addServiceUUID(SERVICE_UUID);
    advertising->start();

    Serial.println("BLE provisioning iniciado");
}

void BLEManager::loop() {
    // inicialmente não precisa fazer nada
}

void BLEManager::setSSID(const String& value) {
    ssid = value;
    ssidReceived = true;

    if (ssidReceived && passwordReceived) {
        credentialsReceived = true;
    }
}

void BLEManager::setPassword(const String& value) {
    password = value;
    passwordReceived = true;

    if (ssidReceived && passwordReceived) {
        credentialsReceived = true;
    }
}

bool BLEManager::hasNewCredentials() {
    return credentialsReceived;
}

String BLEManager::getSSID() {
    return ssid;
}

String BLEManager::getPassword() {
    return password;
}

void BLEManager::stop() {
    BLEDevice::getAdvertising()->stop();
    BLEDevice::deinit(true);
}