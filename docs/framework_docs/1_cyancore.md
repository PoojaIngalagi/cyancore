# 1. Cyancore
### 1.1 Introduction
Cyancore is a standalone framework for building software for embedded systems. It is one such framework that takes advantage of `gnu make` build engine to dynamically build the source trees. It lets a user build various binaries like `firmware or terravisor`, `operating system/kernel or supervisor` and `hypervisor`.

> Supervisor and Hypervisor still needs to be implemented. Currenty there are only placeholders for them.

It is a unified fraemwork which lets developer easily port a platform, create a project, build project and also, change the target platform for a project with as simple as changing 1-2 flags.

### 1.2 Vision
This framework is indented to harbour various platforms and projects and should be able to build any project with any combination of platform. For IoT, this shall be one such software framework which lets developer build any project was ease. Having support from 8bit onwards, a developer has ability to port a project with any target (some changes such as i/o pins and other minor may be necessary).

### 1.3 Framework Design
The key component of the framework is the **build engine**. The modularised makefiles help the build to be easy and smooth without major scripting. Because of such ability, the directory structure is designed the way it is. It provides a very fine control on tree-branch selection for the build and provides myriad of options to pick the modules.
```
src
|- arch         - Dir for CPU arch sources 
|- driver       - Dir for device driver
|- engine       - Dir for cyancore entrypoint after arch init
|- include      - Dir for all header/include files
|- lib          - Dir for library files
|- platform     - Dir for HAL and other sources of platforms
|- project      - Home Dir for all projects
|- visor        - Home Dir for all terravisor, hypervisor and supervisor
\- source.mk    - This is a source config makefile [avoid modification]
```
