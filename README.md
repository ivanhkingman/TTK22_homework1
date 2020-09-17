# Homework submission for TTK22: IMC messaging

# Disclaimer

This repository contains IMC source code from the LSTS open source Software Toolchain.



# Prerequisites

cmake

Neptus


# Instructions

Pull this repository:

```bash
git clone https://github.com/ivanhkingman/TTK22_homework1
```

Open Neptus console:

```bash
cd path/to/neptus/neptus/develop
./neptus.sh
```

then in the Neptus GUI menu select: Systems > LAUV-Xplore-1 and click "Consoles"

Run cmake and make:

```bash
cd path/to/TTK22_homework1/homework_1
mkdir build
cd build
cmake ~/TTK22_homework1
make -j2
```

Verify message in Neptus:

In the Neptus GUI menu select: Communications > IMC Comm. Monitor > All Messages

Call the executable from the build folder and observe the message in the Comm. Monitor

```bash
./hello
```

