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

Detailed information about the application can be found in the _WIKI_ with the following **[INSERT LINK HERE]** 

## File Organization
The application file is organized based on the following format: 

Main Folder Structure | Description
--------------------- | -----------
/data | Contains all required data to successfully run the application. This includes the necessary function named _readFile_ 
/doc | Documentation for the application
/include | Application's header files
/lib | **[INSERT TEXT]**
/src | Application's function sources 
/test | Required information required for application testing
/test/include | Application's header files required for application testing
/test/src | Application's function sources requried for application testing
/test/data |  Contains all required data to successfully test the application. This includes the necessary function named _readFile_ 
/bin | Executables requried for successful application run and tests
/build | Compiler's build files
README.md | Projects ReadMe file
makeFile | MakeFile creation and running individual modules from the main file

## Getting Started

### 1. Dependencies

The following subsections show the main 3rd party depencies' installation methods for both Windows and Linux: 

**Windows Users**

* Cygwin
* CLION IDE

The instructions on how to install these dependencies are found in Section 1 - Software Dependencies of the Wiki. This can also be found with the [link](). 

This repository contains all work completed to date for the Group 1 program project

#Setup Instructions

- Open command prompt in the parent directory of the project
- Run the command "make" to compile the program
- Run the command "cd bin" go inside bin directory
- Run the "index.exe" file to run the program
- Also you can use "make clean" command to delete the object(.o) files
