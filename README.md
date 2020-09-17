# Homework submission for TTK22: IMC messaging

# Prerequisites

cmake

Neptus

Dune

# Instructions

Pull this repository:

```bash
git pull
```

Open Neptus console:

```bash
cd path/to/neptus/neptus/develop
```

then in the Neptus GUI menu select: Systems > LAUV-Xplore-1

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

