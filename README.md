# Datasaurus Node — Temperature & Humidity V1

Hardware reference platform for Datasaurus IoT devices capable of collecting **temperature and relative humidity** data.

This project defines a reusable mechatronic device composed of:

* Electronics
* Embedded firmware
* Mechanical structure
* Manufacturing artifacts
* Technical documentation

The device is designed to serve as a **base platform for multiple Datasaurus applications and products**.

---

## 1. Purpose

`datasaurus-node-temp-humidity-v1` is a generic Datasaurus IoT device for environmental data collection.

The device is intentionally independent of a specific application or business vertical.

The same hardware platform may be used in different products and applications that require temperature and humidity measurements.

Examples:

* Plantário
* Environmental monitoring
* Indoor monitoring
* Greenhouse monitoring
* Equipment monitoring
* Prototyping and experimentation

---

## 2. Device Capabilities

### Measurements

| Capability  | Description           |
| ----------- | --------------------- |
| Temperature | Ambient temperature   |
| Humidity    | Relative air humidity |

### Connectivity

The device is designed to communicate through:

* Wi-Fi
* MQTT
* AWS IoT Core

### Processing

The device uses an ESP32-class microcontroller as its embedded computing platform.

---

## 3. Architecture

```text
┌──────────────────────────────┐
│      Datasaurus Node         │
│                              │
│  ┌────────────┐              │
│  │  Sensors   │              │
│  │            │              │
│  │ Temperature│              │
│  │ Humidity   │              │
│  └─────┬──────┘              │
│        │                     │
│        ▼                     │
│  ┌────────────┐              │
│  │    ESP32   │              │
│  │  Firmware  │              │
│  └─────┬──────┘              │
│        │ Wi-Fi / MQTT        │
└────────┼─────────────────────┘
         │
         ▼
┌──────────────────────────────┐
│        AWS IoT Core          │
└──────────────┬───────────────┘
               │
               ▼
        Datasaurus Platform
```

The device is responsible for **collecting and transmitting data**.

Application-specific processing and business logic should remain outside the generic device whenever possible.

---

## 4. Repository Structure

```text
datasaurus-node-temp-humidity-v1/
│
├── firmware/
│   ├── src/
│   └── README.md
│
├── electronics/
│   ├── schematic/
│   ├── pcb/
│   └── bom/
│
├── mechanical/
│   ├── cad/
│   └── print/
│
├── docs/
│   ├── architecture/
│   ├── electronics/
│   ├── mechanical/
│   └── manufacturing/
│
├── CHANGELOG.md
├── LICENSE
└── README.md
```

Each directory contains the engineering artifacts for one discipline of the device.

---

## 5. Hardware

### Main components

| Component                   | Function                                      |
| --------------------------- | --------------------------------------------- |
| ESP32                       | Embedded controller and connectivity          |
| Temperature/humidity sensor | Environmental measurements                    |
| Power supply                | Device power                                  |
| Supporting components       | Protection, filtering and signal conditioning |

The exact component selection and electrical characteristics are documented in the electronics documentation.

See:

```text
electronics/
```

---

## 6. Firmware

The firmware is responsible for:

1. Device initialization
2. Sensor initialization
3. Temperature acquisition
4. Humidity acquisition
5. Wi-Fi connectivity
6. Time synchronization
7. MQTT communication
8. Data transmission to Datasaurus IoT

Application-specific behavior should be implemented separately from the generic device functionality whenever practical.

See:

```text
firmware/
```

---

## 7. Data Flow

The expected data flow is:

```text
Sensor
   │
   ▼
ESP32
   │
   │ MQTT
   ▼
AWS IoT Core
   │
   ▼
Datasaurus IoT
```

The device should publish measurements using the Datasaurus IoT communication conventions defined by the platform.

---

## 8. Mechanical

The mechanical design contains the physical enclosure and mounting structure required to assemble and protect the device.

Source CAD files are stored under:

```text
mechanical/cad/
```

Manufacturing and 3D-printing files are stored under:

```text
mechanical/print/
```

The CAD model is considered the mechanical source of truth.

The `.3mf` file represents a manufacturing/printing artifact generated from the CAD design.

---

## 9. Electronics

The electronics documentation contains:

* Electrical schematic
* PCB design
* Bill of Materials
* Component specifications
* Manufacturing files

The native design files are the source of truth.

Generated PDFs, Gerbers and other exported files are considered manufacturing or documentation artifacts.

---

## 10. Versioning

This project uses two levels of versioning.

### Device generation

The repository name identifies the hardware generation:

```text
datasaurus-node-temp-humidity-v1
```

`v1` represents the first hardware generation of this device capability.

### Project releases

Software and integrated device states use Git tags:

```text
v0.1.0
v0.2.0
v1.0.0
```

Hardware revisions are identified separately:

```text
PCB Rev A
PCB Rev B

Mechanical Rev A
Mechanical Rev B
```

A release represents a known state of the complete device.

---

## 11. Derivatives

This device is intended to be reused as a base for Datasaurus products.

A product may extend or adapt this platform for a specific application.

For example:

```text
datasaurus-node-temp-humidity-v1
              │
              ├── Plantário
              ├── Greenhouse Monitor
              └── Environmental Monitor
```

A derivative should preserve the generic functionality of the base platform whenever practical and add only the functionality required by the specific application.

---

## 12. Design Principles

The project follows these principles:

### Reusability

The device should be applicable to multiple Datasaurus products.

### Modularity

Hardware, firmware and mechanical components should remain independently understandable and replaceable.

### Reproducibility

Another engineer should be able to understand and reproduce the device using the repository contents.

### Separation of concerns

Generic device capabilities should remain separated from application-specific business logic.

### Traceability

Every manufactured device should be traceable to a known hardware revision and software release.

---

## 13. Current Status

**Status:** Prototype

**Hardware:** V1

**Firmware:** Initial development

**Mechanical:** Initial development

**Production:** Not released

---

## 14. Roadmap

* [ ] Finalize electronic schematic
* [ ] Finalize component selection
* [ ] Develop PCB
* [ ] Develop enclosure
* [ ] Implement temperature acquisition
* [ ] Implement humidity acquisition
* [ ] Implement Wi-Fi management
* [ ] Implement MQTT communication
* [ ] Integrate with AWS IoT Core
* [ ] Validate data transmission
* [ ] Validate long-term operation
* [ ] Create manufacturing documentation
* [ ] Release V1

---

## 15. Datasaurus

**Datasaurus IoT — Intelligence of Things**

This device is part of the Datasaurus IoT hardware platform.
