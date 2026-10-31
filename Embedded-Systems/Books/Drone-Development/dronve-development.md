# Vocab
1. **LIDAR:** light detection and ranging.

# Chapter 1, intro to UAVs and Drone Engineering (101)
## What are UAVs?
**Unmanned aerial vehicles** are type of vehicles that fly in the air without any onboard crew and with the help of onboard sophisticated sensor systems.

## What are different types of drones?
### Multirotor drone
Motor-propeller-based drone. *How does one work?:*
- Motors and propellers are the main elements keeping drone in the air.
- That force produces thrust in the drone and helps to lift the system's load.

#### What are some sub-types of these multirotor drones?
1. *Bi-copter*: drone with 2 motors place on each side of the center. 
    - Low Endurance
    - Low Control

2. *tri-copter*: drone with 3 motors placed on each of the 3 arms, each arm is placed at 120 degrees of each other.
    - small size
    - not load carrying
    - ok for short distances inspection and surveillance

3. *quad-copter*: 4 motors.
    - easy to control
    - stable 
    - can carry a few kilos

4. *hexa-copter*: 6 motors drone.
    - less endurance
    - more stability
    - more carry load

5. *octo-copter:* 8 motor drone.
    - carries much more weight
    - very stable
    - low endurance

6. *octa-quad:* 8 motors but 2 are placed on each of the 4 arms.
    - good size to weight ratio

7. *deca-hexa copter*: 12 motors drone where it has 6 arms and each of the arms has 2 motors on it.
    - can carry people (usually).

### Fixed-wing drone
A standard airfoil wing-based design where the wing serves as a key lift generator for the system. A single motor (push/pull) helps to cruise in the air. The cruise speed helps to generate adeqaute lift via wings to travel in the air.

#### What are some sub types of fixed wing drones?
1. **VTOL**, vertical take-off and landing aircraft.
    - uses 4 motors to lift into the air
    - once lifted into air transitions into a fixed-wing aircraft.

2. **Tilt-rotor drone**, hybrid like VTOL but where the same motors are used for both lift off and cruising.
    - at 90 degrees motors lift it off.
    - at 180 degrees motors cruise.
    - more energy efficient than VTOLs due to less motors.

### What about the drone weight classes?
According to Indian gov, DGCA:
1. **nano:** <=250 grams
2. **micro**: 250 grams to 2kg
3. **small**: 2kg to 25kg
4. **medium** 25kg to 150kg
5. **large**: >150kg

## What is the composition of a UAV system?
1. **Body frame** - foundation of a drone
2. **flight control unit (FCU)** - controls flight speed and directions
3. **Onboard computer** - navigation and computation
4. **communication module** - comm. with GCS and UAVs
5. **payload** - carry third party equipment
6. **power system** - supply power for all modules

## What are mechanical components of a drone?
1. **Airframe**, skeleton of the drone.
    - *motor mounts*
    - *arms*, connects motor mounts to main body
    - *hub*, main body where all the compute lives
    - *landing gear*, well the stuff that touches the ground when drone lands

### VERY IMPORTANT DESIGN DECISIONs for AIRFRAMES
1. AIRFRAME MUST BE SYMMETRIC on all aspect of x, y, z
2. MANUFACTURING OF AIRFRAME MUST BE DONE WITH LIGHTWEIGHT MATERIAL
3. A SCREWLESS DESIGN IS IDEAL for stability

## What is the propulsion system or drive train of a drone?
The system that creates the necessary force to lift and keep the drone in the air. Consists of:
1. **Motors:** brushless DC (BLDC) motors, efficient and have long life.
2. **Propellers:** mounted on motors and generate the thrust.

## What is the power system of a drone?
This system is responsible for powering the drone electronics, its payload and other on-board peripherals.
1. **Battery:** the source of power for the whole system.
2. **Power distribution board**: distributes power to different systems. Has filtering components that ensure parts dont burn due to surges.
3. **buck-and-boost converters:** used to step up or down the voltage as required by different devices.


## What is the command and control system of a drone?
The system that allows the drone to be controlled, also lets you enable real-time monitoring of the drone's health through sensor data.
1. **Remote control (RC)**:
2. **Ground control station (GCS):**
3. **Radio Modem:**
