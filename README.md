# Group 1 - Optimization of Budget Management for Product Restocking

## Table of Contents

* Team Members
* Application Overview
* File Organization
* Getting Started 
  *  1. Dependencies
  *  2. Building the Software
  *  3. Testing the Software
  *  4. Running the Main Application
* Documentation

## Team Members 

Organization: Carleton University

Course: SYSC 4006 A - Introduction to Systems Programming

Authors:

Student Name | GITHub ID
------------ | ---------
Abraheim Alokby | AbraheimAlokby
Kanwar Roop Singh | kanwar-roop-singh
Jeetkumar Thummar | jeetthummar 

## Application Overview

This software aims to improve the management of product purchases within a company to optimize the total profits that are expected within a fiscal period. To achieve this, the program will allow the users to: 

* Submit a valid readable file labelled, **_readFile_**, containing the completed company data for the stored products during the previous fiscal time period. 
* Check the data file through the command line, with the choice of adding/removing or modifying chosen product data.
* Run and with the final completed data to determine the chosen items for restocking based on a **Ranked List** policy.
* View the final decision of the algorithm for what which products had been selected for restocking and how many of those products where selected. 

Detailed information about the application can be found in the _WIKI_ with the following [link](https://github.com/AbraheimAlokby/Group_001_Optimization-of-Budget-Management-for-Product-Restocking/wiki). 

## File Organization
The application file is organized based on the following format: 

Main Folder Structure | Description
--------------------- | -----------
/data | Contains all required data to successfully run the application. This includes the necessary function named _readFile_ 
/doc | Documentation for the application
/include | Application's header files
/src | Application's function sources 
/test | Required information required for application testing
/test/include | Application's header files required for application testing
/test/src | Application's function sources requried for application testing
/test/data |  Contains all required data to successfully test the application. This includes the necessary function named _readFile_ 
/bin | Executables requried for successful application run and tests
/build | Compiler's build files
README.md | Projects ReadMe file
makeFile | MakeFile creation and running individual modules from the main file

The detailed folder structure is given [here](https://github.com/AbraheimAlokby/Group_001_Optimization-of-Budget-Management-for-Product-Restocking/wiki/3.-Software-User-Manual#folder-structure) 

## Getting Started

### 1. Dependencies

The following subsections show the main 3rd party depencies' installation methods for both Windows and Linux: 

**Windows Users**

* Cygwin
* CLION IDE
* GIT GUI

The instructions on how to install these dependencies are found in Section 1 - Software Dependencies of the _Wiki_. This can also be found with the [link](https://github.com/AbraheimAlokby/Group_001_Optimization-of-Budget-Management-for-Product-Restocking/wiki/1.-Software-Dependencies). 

This repository contains all work completed to date for the Group 1 program project

## 2. Cloning the Github Repository

You can clone the projects repository from GitHub.com to your local computer to make it easier to fix merge conflicts, add or remove files, and push larger commits. When you clone the repository, you copy the repository from GitHub.com to your local machine.

Cloning this repository pulls down a full copy of all the data and files found in GitHub, including all versions of every file and folder for the project. The instruction to pull a full copy for individual testing is found below: 

1. Find the main page of the repository on Git Hub, and above the list of files click the down arrow of the green bar that says **CLONE**. 
2. To clone the repository using HTTPS, under "Clone with HTTPS", click the two overlapping square boxes next to the textbox containing the URL. To clone the repository using an SSH key,  click Use SSH, then click the two overlapping square boxes next to the textbox containing the URL. Finally, to clone a repository using GitHub CLI, click Use GitHub CLI, then click the two overlapping square boxes next to the textbox containing the URL.
3. Open GIT GUI that was installed on your local system previously. 
4. Select _Clone Existing Repository_.
5. Select where you would want to install a new folder to install the repository in _Target Directory_.
6. Paste the repository link, found in Step 2, within the _Source Location_ box. 
7. Click on _Clone_. 
8. The software repository is now cloned on your local computer


## 3. Running the Software

Once all the required independencies have been installed, follow the following instructions to completely run the program: 

1. Open command prompt in the parent directory of the project
2. Run the command `make all` to compile the program
3. Run the command `make test` to compile the testing script
4. Run the command `cd bin` go inside bin directory
5. Run the `index.exe` file to run the program
6. Run the `test.exe` file to run the testing script
7. Also you can use `make clean` command to delete the object(.o) files


## 4. Developer Manual

The developer manual is available [here](https://github.com/AbraheimAlokby/Group_001_Optimization-of-Budget-Management-for-Product-Restocking/wiki) \
This [link](https://jeetthummar.github.io/Doxygen/) provides the HTML documentation generated by Doxygen.
## Acknowledgements

We thank Dr. Cristina Ruiz Martin for guiding us through the different development stages 